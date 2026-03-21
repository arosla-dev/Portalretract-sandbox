//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: Special handling for Portal usable ladders
//
//=============================================================================//
#include "cbase.h"
#include "hl_gamemovement.h"
#include "in_buttons.h"
#include "utlrbtree.h"
#include "movevars_shared.h"
#include "portal_shareddefs.h"
#include "portal_collideable_enumerator.h"
#include "prop_portal_shared.h"
#include "rumble_shared.h"
#include "hl2_shareddefs.h"

#if defined( CLIENT_DLL )
	#include "c_portal_player.h"
	#include "c_rumble.h"
#else
	#include "portal_player.h"
	#include "env_player_surface_trigger.h"
	#include "portal_gamestats.h"
	#include "physicsshadowclone.h"
	#include "recipientfilter.h"
	#include "SoundEmitterSystem/isoundemittersystembase.h"
#endif

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

ConVar sv_player_trace_through_portals("sv_player_trace_through_portals", "1", FCVAR_REPLICATED | FCVAR_CHEAT, "Causes player movement traces to trace through portals." );
ConVar sv_player_funnel_into_portals("sv_player_funnel_into_portals", "1", FCVAR_REPLICATED | FCVAR_ARCHIVE | FCVAR_ARCHIVE_XBOX, "Causes the player to auto correct toward the center of floor portals." ); 

ConVar sv_speed_paint_max("sv_speed_paint_max", "800.0f", FCVAR_REPLICATED | FCVAR_CHEAT, "For tweaking the max speed for speed paint.");
ConVar sv_speed_paint_side_move_factor("sv_speed_paint_side_move_factor", "0.5f", FCVAR_REPLICATED | FCVAR_CHEAT);

class CReservePlayerSpot;

#define PORTAL_FUNNEL_AMOUNT 6.0f

extern bool g_bAllowForcePortalTrace;
extern bool g_bForcePortalTrace;

static inline CBaseEntity *TranslateGroundEntity( CBaseEntity *pGroundEntity )
{
#ifndef CLIENT_DLL
	CPhysicsShadowClone *pClone = dynamic_cast<CPhysicsShadowClone *>(pGroundEntity);

	if( pClone && pClone->IsUntransformedClone() )
	{
		CBaseEntity *pSource = pClone->GetClonedEntity();

		if( pSource )
			return pSource;
	}
#endif //#ifndef CLIENT_DLL

	return pGroundEntity;
}


//-----------------------------------------------------------------------------
// Purpose: Portal specific movement code
//-----------------------------------------------------------------------------
class CPortalGameMovement : public CHL2GameMovement
{
	typedef CGameMovement BaseClass;
public:

	CPortalGameMovement();

	bool	m_bInPortalEnv;
// Overrides
	virtual void ProcessMovement( CBasePlayer *pPlayer, CMoveData *pMove );
	virtual bool CheckJumpButton( void );

	void FunnelIntoPortal( CProp_Portal *pPortal, Vector &wishdir );

	virtual void AirAccelerate( Vector& wishdir, float wishspeed, float accel );
	virtual void AirMove( void );

	virtual void PlayerRoughLandingEffects( float fvol );

	virtual void CategorizePosition( void );
	
	virtual void CheckParameters( void );

	// Traces the player bbox as it is swept from start to end
	virtual void TracePlayerBBox( const Vector& start, const Vector& end, unsigned int fMask, int collisionGroup, trace_t& pm );

	// Tests the player position
	virtual CBaseHandle	TestPlayerPosition( const Vector& pos, int collisionGroup, trace_t& pm );

	virtual void Duck( void );				// Check for a forced duck

	virtual int CheckStuck( void );

	virtual void SetGroundEntity( trace_t *pm );

	// Handle MOVETYPE_WALK.
	virtual void	FullWalkMove();

private:
	
	virtual void	TBeamMove();

	CPortal_Player	*GetPortalPlayer();
};

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
CPortalGameMovement::CPortalGameMovement()
{
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
inline CPortal_Player	*CPortalGameMovement::GetPortalPlayer()
{
	return static_cast< CPortal_Player * >( player );
}

//-----------------------------------------------------------------------------
// Purpose: 
// Input  : *pMove - 
//-----------------------------------------------------------------------------
void CPortalGameMovement::ProcessMovement( CBasePlayer *pPlayer, CMoveData *pMove )
{
	Assert( pMove && pPlayer );

	float flStoreFrametime = gpGlobals->frametime;

	//!!HACK HACK: Adrian - slow down all player movement by this factor.
	//!!Blame Yahn for this one.
	gpGlobals->frametime *= pPlayer->GetLaggedMovementValue();

	ResetGetPointContentsCache();

	// Cropping movement speed scales mv->m_fForwardSpeed etc. globally
	// Once we crop, we don't want to recursively crop again, so we set the crop
	//  flag globally here once per usercmd cycle.
	m_iSpeedCropped = SPEED_CROPPED_RESET;

	player = pPlayer;
	mv = pMove;
	mv->m_flMaxSpeed = sv_maxspeed.GetFloat();
	
	m_bInPortalEnv = (((CPortal_Player *)pPlayer)->m_hPortalEnvironment != NULL);

	g_bAllowForcePortalTrace = m_bInPortalEnv;
	g_bForcePortalTrace = m_bInPortalEnv;

	Vector vForward, vRight;
	AngleVectors( mv->m_vecViewAngles, &vForward, &vRight, NULL );  // Determine movement angles

	const Vector worldUp( 0, 0, 1 );
	bool shouldProjectInputVectorsOntoGround = pPlayer->GetGroundEntity() != NULL;

	if( shouldProjectInputVectorsOntoGround )
	{
		vForward -= DotProduct( vForward, worldUp ) * worldUp;
		vRight -= DotProduct( vRight, worldUp ) * worldUp;

		vForward.NormalizeInPlace();
		vRight.NormalizeInPlace();
	}
	
	Vector vWishVel = vForward*mv->m_flForwardMove + vRight*mv->m_flSideMove;
	vWishVel -= worldUp * DotProduct( vWishVel, worldUp );
	
	GetPortalPlayer()->SetInputVector( vWishVel );
	GetPortalPlayer()->UpdatePaintPowers();

	// Using the paint power may change the velocity
	mv->m_vecVelocity = player->GetAbsVelocity();
	
	// Use this player's max speed (dependent on whether he's on speed paint)
	const float maxSpeed = pPlayer->MaxSpeed();
	mv->m_flClientMaxSpeed = mv->m_flMaxSpeed = maxSpeed;

	// Run the command.
	PlayerMove();

	FinishMove();

	g_bAllowForcePortalTrace = false;
	g_bForcePortalTrace = false;

#ifndef CLIENT_DLL
	pPlayer->UnforceButtons( IN_DUCK );
	pPlayer->UnforceButtons( IN_JUMP );
#endif

	//This is probably not needed, but just in case.
	gpGlobals->frametime = flStoreFrametime;
}

//-----------------------------------------------------------------------------
// Purpose: Base jump behavior, plus an anim event
// Input  :  - 
// Output : Returns true on success, false on failure.
//-----------------------------------------------------------------------------
bool CPortalGameMovement::CheckJumpButton()
{
	if ( BaseClass::CheckJumpButton() && GetPortalPlayer() )
	{
		GetPortalPlayer()->DoAnimationEvent( PLAYERANIMEVENT_JUMP, 0 );
		return true;
	}

	return false;
}

void CPortalGameMovement::FunnelIntoPortal( CProp_Portal *pPortal, Vector &wishdir )
{
	// Make sure there's a portal
	if ( !pPortal )
		return;

	// Get portal vectors
	Vector vPortalForward, vPortalRight, vPortalUp;
	pPortal->GetVectors( &vPortalForward, &vPortalRight, &vPortalUp );

	// Make sure it's a floor portal
	if ( vPortalForward.z < 0.8f )
		return;

	vPortalRight.z = 0.0f;
	vPortalUp.z = 0.0f;
	VectorNormalize( vPortalRight );
	VectorNormalize( vPortalUp );

	// Make sure the player is looking downward
	CPortal_Player *pPlayer = GetPortalPlayer();

	Vector vPlayerForward;
	pPlayer->EyeVectors( &vPlayerForward );

	if ( vPlayerForward.z > -0.1f )
		return;

	Vector vPlayerOrigin = pPlayer->GetAbsOrigin();
	Vector vPlayerToPortal = pPortal->GetAbsOrigin() - vPlayerOrigin;

	// Make sure the player is trying to air control, they're falling downward and they are vertically close to the portal
	if ( fabsf( wishdir[ 0 ] ) > 64.0f || fabsf( wishdir[ 1 ] ) > 64.0f || mv->m_vecVelocity[ 2 ] > -165.0f || vPlayerToPortal.z < -512.0f )
		return;

	// Make sure we're in the 2D portal rectangle
	if ( ( vPlayerToPortal.Dot( vPortalRight ) * vPortalRight ).Length() > PORTAL_HALF_WIDTH * 1.5f )
		return;
	if ( ( vPlayerToPortal.Dot( vPortalUp ) * vPortalUp ).Length() > PORTAL_HALF_HEIGHT * 1.5f )
		return;

	if ( vPlayerToPortal.z > -8.0f )
	{
		// We're too close the the portal to continue correcting, but zero the velocity so our fling velocity is nice
		mv->m_vecVelocity[ 0 ] = 0.0f;
		mv->m_vecVelocity[ 1 ] = 0.0f;
	}
	else
	{
		// Funnel toward the portal
		float fFunnelX = vPlayerToPortal.x * PORTAL_FUNNEL_AMOUNT - mv->m_vecVelocity[ 0 ];
		float fFunnelY = vPlayerToPortal.y * PORTAL_FUNNEL_AMOUNT - mv->m_vecVelocity[ 1 ];

		wishdir[ 0 ] += fFunnelX;
		wishdir[ 1 ] += fFunnelY;
	}
}

//-----------------------------------------------------------------------------
// Purpose: 
// Input  : wishdir - 
//			accel - 
//-----------------------------------------------------------------------------
void CPortalGameMovement::AirAccelerate( Vector& wishdir, float wishspeed, float accel )
{
	int i;
	float addspeed, accelspeed, currentspeed;
	float wishspd;

	wishspd = wishspeed;

	if (player->pl.deadflag)
		return;

	if (player->m_flWaterJumpTime)
		return;

	// Cap speed
	if (wishspd > 60.0f)
		wishspd = 60.0f;

	// Determine veer amount
	currentspeed = mv->m_vecVelocity.Dot(wishdir);

	// See how much to add
	addspeed = wishspd - currentspeed;

	// If not adding any, done.
	if (addspeed <= 0)
		return;

	// Determine acceleration speed after acceleration
	accelspeed = accel * wishspeed * gpGlobals->frametime * player->m_surfaceFriction;

	// Cap it
	if (accelspeed > addspeed)
		accelspeed = addspeed;

	// Adjust pmove vel.
	for (i=0 ; i<3 ; i++)
	{
		mv->m_vecVelocity[i] += accelspeed * wishdir[i];
		mv->m_outWishVel[i] += accelspeed * wishdir[i];
	}
}

void CPortalGameMovement::TBeamMove( void )
{
	CPortal_Player *pPortalPlayer = GetPortalPlayer();

	CTrigger_TractorBeam *pTractorBeam = pPortalPlayer->GetTractorBeam();
	if ( !pTractorBeam )
		return;

	if ( gpGlobals->frametime > 0.0f )
	{
		Vector vLinear;
		AngularImpulse angAngular;
		vLinear.Init();
		angAngular.Init();

		pTractorBeam->CalculateFrameMovement( NULL, pPortalPlayer, gpGlobals->frametime, vLinear, angAngular );
		mv->m_vecVelocity += vLinear * gpGlobals->frametime;
	}

	TryPlayerMove( 0, 0 );
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CPortalGameMovement::AirMove( void )
{
	int			i;
	Vector		wishvel;
	float		fmove, smove;
	Vector		wishdir;
	float		wishspeed;
	Vector forward, right, up;

	AngleVectors (mv->m_vecViewAngles, &forward, &right, &up);  // Determine movement angles

	// Copy movement amounts
	fmove = mv->m_flForwardMove;
	smove = mv->m_flSideMove;

	// Zero out z components of movement vectors
	forward[2] = 0;
	right[2]   = 0;
	VectorNormalize(forward);  // Normalize remainder of vectors
	VectorNormalize(right);    // 

	for (i=0 ; i<2 ; i++)       // Determine x and y parts of velocity
		wishvel[i] = forward[i]*fmove + right[i]*smove;
	wishvel[2] = 0;             // Zero out z part of velocity

	VectorCopy (wishvel, wishdir);   // Determine maginitude of speed of move

	//
	// Don't let the player screw their fling because of adjusting into a floor portal
	//
	if ( mv->m_vecVelocity[ 0 ] * mv->m_vecVelocity[ 0 ] + mv->m_vecVelocity[ 1 ] * mv->m_vecVelocity[ 1 ] > MIN_FLING_SPEED * MIN_FLING_SPEED )
	{
		if ( mv->m_vecVelocity[ 0 ] > MIN_FLING_SPEED * 0.5f && wishdir[ 0 ] < 0.0f )
			wishdir[ 0 ] = 0.0f;
		else if ( mv->m_vecVelocity[ 0 ] < -MIN_FLING_SPEED * 0.5f && wishdir[ 0 ] > 0.0f )
			wishdir[ 0 ] = 0.0f;

		if ( mv->m_vecVelocity[ 1 ] > MIN_FLING_SPEED * 0.5f && wishdir[ 1 ] < 0.0f )
			wishdir[ 1 ] = 0.0f;
		else if ( mv->m_vecVelocity[ 1 ] < -MIN_FLING_SPEED * 0.5f && wishdir[ 1 ] > 0.0f )
			wishdir[ 1 ] = 0.0f;
	}

	//
	// Try to autocorrect the player to fall into the middle of the portal
	//
	else if ( sv_player_funnel_into_portals.GetBool() )
	{
		int iPortalCount = CProp_Portal_Shared::AllPortals.Count();
		if( iPortalCount != 0 )
		{
			CProp_Portal **pPortals = CProp_Portal_Shared::AllPortals.Base();
			for( int i = 0; i != iPortalCount; ++i )
			{
				CProp_Portal *pTempPortal = pPortals[i];
				if( pTempPortal->IsActivedAndLinked() )
				{
					FunnelIntoPortal( pTempPortal, wishdir );
				}
			}
		}
	}

	wishspeed = VectorNormalize(wishdir);

	//
	// clamp to server defined max speed
	//
	if ( wishspeed != 0 && (wishspeed > mv->m_flMaxSpeed))
	{
		VectorScale (wishvel, mv->m_flMaxSpeed/wishspeed, wishvel);
		wishspeed = mv->m_flMaxSpeed;
	}

	AirAccelerate( wishdir, wishspeed, 15.0f );

	// Add in any base velocity to the current velocity.
	VectorAdd(mv->m_vecVelocity, player->GetBaseVelocity(), mv->m_vecVelocity );

	TryPlayerMove();

	// Now pull the base velocity back out.   Base velocity is set if you are on a moving object, like a conveyor (or maybe another monster?)
	VectorSubtract( mv->m_vecVelocity, player->GetBaseVelocity(), mv->m_vecVelocity );
}

void CPortalGameMovement::PlayerRoughLandingEffects( float fvol )
{
	BaseClass::PlayerRoughLandingEffects( fvol );

#ifndef CLIENT_DLL
	if ( fvol >= 1.0 )
	{
		// Play the future shoes sound
		CRecipientFilter filter;
		filter.AddRecipientsByPAS( player->GetAbsOrigin() );

		CSoundParameters params;
		if ( CBaseEntity::GetParametersForSound( "PortalPlayer.FallRecover", params, NULL ) )
		{
			EmitSound_t ep( params );
			ep.m_nPitch = 125.0f - player->m_Local.m_flFallVelocity * 0.03f;					// lower pitch the harder they land
			ep.m_flVolume = MIN( player->m_Local.m_flFallVelocity * 0.00075f - 0.38, 1.0f );	// louder the harder they land

			CBaseEntity::EmitSound( filter, player->entindex(), ep );
		}
	}
#endif
}

void TracePlayerBBoxForGround2( const Vector& start, const Vector& end, const Vector& minsSrc,
							   const Vector& maxsSrc, IHandleEntity *player, unsigned int fMask,
							   int collisionGroup, trace_t& pm )
{

	VPROF( "TracePlayerBBoxForGround" );

	CPortal_Player *pPortalPlayer = dynamic_cast<CPortal_Player *>(player->GetRefEHandle().Get());
	CProp_Portal *pPlayerPortal = pPortalPlayer->m_hPortalEnvironment;

#ifndef CLIENT_DLL
	if( pPlayerPortal && pPlayerPortal->m_PortalSimulator.IsReadyToSimulate() == false )
		pPlayerPortal = NULL;
#endif

	Ray_t ray;
	Vector mins, maxs;

	float fraction = pm.fraction;
	Vector endpos = pm.endpos;

	// Check the -x, -y quadrant
	mins = minsSrc;
	maxs.Init( MIN( 0, maxsSrc.x ), MIN( 0, maxsSrc.y ), maxsSrc.z );
	ray.Init( start, end, mins, maxs );

	if( pPlayerPortal )
		UTIL_Portal_TraceRay( pPlayerPortal, ray, fMask, player, collisionGroup, &pm );
	else
		UTIL_TraceRay( ray, fMask, player, collisionGroup, &pm );

	if ( pm.m_pEnt && pm.plane.normal[2] >= 0.7)
	{
		pm.fraction = fraction;
		pm.endpos = endpos;
		return;
	}

	// Check the +x, +y quadrant
	mins.Init( MAX( 0, minsSrc.x ), MAX( 0, minsSrc.y ), minsSrc.z );
	maxs = maxsSrc;
	ray.Init( start, end, mins, maxs );

	if( pPlayerPortal )
		UTIL_Portal_TraceRay( pPlayerPortal, ray, fMask, player, collisionGroup, &pm );
	else
		UTIL_TraceRay( ray, fMask, player, collisionGroup, &pm );

	if ( pm.m_pEnt && pm.plane.normal[2] >= 0.7)
	{
		pm.fraction = fraction;
		pm.endpos = endpos;
		return;
	}

	// Check the -x, +y quadrant
	mins.Init( minsSrc.x, MAX( 0, minsSrc.y ), minsSrc.z );
	maxs.Init( MIN( 0, maxsSrc.x ), maxsSrc.y, maxsSrc.z );
	ray.Init( start, end, mins, maxs );

	if( pPlayerPortal )
		UTIL_Portal_TraceRay( pPlayerPortal, ray, fMask, player, collisionGroup, &pm );
	else
		UTIL_TraceRay( ray, fMask, player, collisionGroup, &pm );

	if ( pm.m_pEnt && pm.plane.normal[2] >= 0.7)
	{
		pm.fraction = fraction;
		pm.endpos = endpos;
		return;
	}

	// Check the +x, -y quadrant
	mins.Init( MAX( 0, minsSrc.x ), minsSrc.y, minsSrc.z );
	maxs.Init( maxsSrc.x, MIN( 0, maxsSrc.y ), maxsSrc.z );
	ray.Init( start, end, mins, maxs );

	if( pPlayerPortal )
		UTIL_Portal_TraceRay( pPlayerPortal, ray, fMask, player, collisionGroup, &pm );
	else
		UTIL_TraceRay( ray, fMask, player, collisionGroup, &pm );

	if ( pm.m_pEnt && pm.plane.normal[2] >= 0.7)
	{
		pm.fraction = fraction;
		pm.endpos = endpos;
		return;
	}

	pm.fraction = fraction;
	pm.endpos = endpos;
}

//-----------------------------------------------------------------------------
// Purpose: 
// Input  : &input - 
//-----------------------------------------------------------------------------
void CPortalGameMovement::CategorizePosition( void )
{
	Vector point;
	trace_t pm;

	// Reset this each time we-recategorize, otherwise we have bogus friction when we jump into water and plunge downward really quickly
	player->m_surfaceFriction = 1.0f;

	// if the player hull point one unit down is solid, the player
	// is on ground
	
	// see if standing on something solid	

	// Doing this before we move may introduce a potential latency in water detection, but
	// doing it after can get us stuck on the bottom in water if the amount we move up
	// is less than the 1 pixel 'threshold' we're about to snap to.	Also, we'll call
	// this several times per frame, so we really need to avoid sticking to the bottom of
	// water on each call, and the converse case will correct itself if called twice.
	CheckWater();

	// observers don't have a ground entity
	if ( player->IsObserver() )
		return;

	float flOffset = 2.0f;

	point[0] = mv->GetAbsOrigin()[0];
	point[1] = mv->GetAbsOrigin()[1];
	point[2] = mv->GetAbsOrigin()[2] - flOffset;

	Vector bumpOrigin;
	bumpOrigin = mv->GetAbsOrigin();

	// Shooting up really fast.  Definitely not on ground.
	// On ladder moving up, so not on ground either
	// NOTE: 145 is a jump.
#define NON_JUMP_VELOCITY 140.0f

	float zvel = mv->m_vecVelocity[2];
	bool bMovingUp = zvel > 0.0f;
	bool bMovingUpRapidly = zvel > NON_JUMP_VELOCITY && ((player->GetGroundEntity() == NULL) || IsInactivePower( GetPortalPlayer()->GetPaintPower( SPEED_POWER )));
	float flGroundEntityVelZ = 0.0f;
	if ( bMovingUpRapidly )
	{
		// Tracker 73219, 75878:  ywb 8/2/07
		// After save/restore (and maybe at other times), we can get a case where we were saved on a lift and 
		//  after restore we'll have a high local velocity due to the lift making our abs velocity appear high.  
		// We need to account for standing on a moving ground object in that case in order to determine if we really 
		//  are moving away from the object we are standing on at too rapid a speed.  Note that CheckJump already sets
		//  ground entity to NULL, so this wouldn't have any effect unless we are moving up rapidly not from the jump button.
		CBaseEntity *ground = player->GetGroundEntity();
		if ( ground )
		{
			flGroundEntityVelZ = ground->GetAbsVelocity().z;
			bMovingUpRapidly = ( zvel - flGroundEntityVelZ ) > NON_JUMP_VELOCITY;
		}
	}

	// NOTE YWB 7/5/07:  Since we're already doing a traceline here, we'll subsume the StayOnGround (stair debouncing) check into the main traceline we do here to see what we're standing on
	bool bUnderwater = ( player->GetWaterLevel() >= WL_Eyes );
	bool bMoveToEndPos = false;
	if ( player->GetMoveType() == MOVETYPE_WALK && 
		player->GetGroundEntity() != NULL && !bUnderwater )
	{
		// if walking and still think we're on ground, we'll extend trace down by stepsize so we don't bounce down slopes
		bMoveToEndPos = true;
		point.z -= player->m_Local.m_flStepSize;
	}

	// Was on ground, but now suddenly am not
	if ( bMovingUpRapidly || 
		( bMovingUp && player->GetMoveType() == MOVETYPE_LADDER ) )   
	{
		SetGroundEntity( NULL );
		bMoveToEndPos = false;
	}
	else
	{
		// Try and move down.
		TracePlayerBBox( bumpOrigin, point, PlayerSolidMask(), COLLISION_GROUP_PLAYER_MOVEMENT, pm );

		const Vector vPrevGroundNormal = GetPortalPlayer()->GetPrevGroundNormal();

		float fDot = DotProduct( vPrevGroundNormal, pm.plane.normal );
		float fSpeed = mv->m_vecVelocity.Length();
		bool bRampLaunch = false;

		// Fast enough to launch and surface slopes have a sharp enough change?
		if( GetPortalPlayer()->GetGroundEntity() &&		// We're on the ground this frame
			fSpeed > sv_maxspeed.GetFloat() &&	// Our speed is greater than the normal (ie. we're on speed paint)
			( fDot < 1.f ||	!pm.DidHit() )	)	// And the trace did not hit or there was a significant change in surface normals
		{

			// Find out if the slope went up or down
			Vector vVelCrossUp = CrossProduct( mv->m_vecVelocity.Normalized(), Vector(0,0,1) );
			Vector vNewNormCrossOldNorm = CrossProduct( pm.plane.normal, vPrevGroundNormal );
			float fCrossDot = DotProduct( vVelCrossUp, vNewNormCrossOldNorm );
			// If it was a downward change then launch off of it
			if( fCrossDot > EQUAL_EPSILON || ( vPrevGroundNormal.Length2DSqr() && !pm.DidHit() ) )
			{
				bRampLaunch = true;

				// Compute normalized forward direction in tangent plane of the ramp
				const Vector vWishDirection = mv->m_vecVelocity;
				const Vector vTangentRight = CrossProduct( vWishDirection, vPrevGroundNormal );
				const Vector vNormTangentForward = CrossProduct( vPrevGroundNormal, vTangentRight ).Normalized();

				mv->m_vecVelocity = vNormTangentForward * mv->m_vecVelocity.Length();
			}
		}

		// Was on ground, but now suddenly am not.  If we hit a steep plane, we are not on ground
		float flStandableZ = 0.7;



		if ( !pm.m_pEnt || ( pm.plane.normal[2] < flStandableZ ) || bRampLaunch )
		{
			// Test four sub-boxes, to see if any of them would have found shallower slope we could actually stand on
			TracePlayerBBoxForGround2( bumpOrigin, point, GetPlayerMins(), GetPlayerMaxs(), mv->m_nPlayerHandle.Get(), MASK_PLAYERSOLID, COLLISION_GROUP_PLAYER_MOVEMENT, pm );
			if ( !pm.m_pEnt || ( pm.plane.normal[2] < flStandableZ ) || bRampLaunch )
			{
				SetGroundEntity( NULL );
				// probably want to add a check for a +z velocity too!
				if ( ( mv->m_vecVelocity.z > 0.0f ) && 
					( player->GetMoveType() != MOVETYPE_NOCLIP ) )
				{
					player->m_surfaceFriction = 0.25f;
				}
				bMoveToEndPos = false;
			}
			else
			{
				SetGroundEntity( &pm );
			}
		}
		else
		{
			SetGroundEntity( &pm );  // Otherwise, point to index of ent under us.
		}

#ifndef CLIENT_DLL

		//Adrian: vehicle code handles for us.
		if ( player->IsInAVehicle() == false )
		{
			// If our gamematerial has changed, tell any player surface triggers that are watching
			IPhysicsSurfaceProps *physprops = MoveHelper()->GetSurfaceProps();
			surfacedata_t *pSurfaceProp = physprops->GetSurfaceData( pm.surface.surfaceProps );
			char cCurrGameMaterial = pSurfaceProp->game.material;
			if ( !player->GetGroundEntity() )
			{
				cCurrGameMaterial = 0;
			}

			// Changed?
			if ( player->m_chPreviousTextureType != cCurrGameMaterial )
			{
				CEnvPlayerSurfaceTrigger::SetPlayerSurface( player, cCurrGameMaterial );
			}

			player->m_chPreviousTextureType = cCurrGameMaterial;
		}
#endif
	}

	// YWB:  This logic block essentially lifted from StayOnGround implementation
	if ( bMoveToEndPos &&
		!pm.startsolid &&				// not sure we need this check as fraction would == 0.0f?
		pm.fraction > 0.0f &&			// must go somewhere
		pm.fraction < 1.0f ) 			// must hit something
	{
		mv->SetAbsOrigin( pm.endpos );
	}
	
	// Save the normal of the surface if we hit something
	if( GetPortalPlayer()->GetGroundEntity() != NULL && pm.DidHit() )
	{
		GetPortalPlayer()->SetPrevGroundNormal( pm.plane.normal );
	}
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CPortalGameMovement::CheckParameters( void )
{
	QAngle	v_angle;

	if ( player->GetMoveType() != MOVETYPE_ISOMETRIC &&
		 player->GetMoveType() != MOVETYPE_NOCLIP &&
		 player->GetMoveType() != MOVETYPE_OBSERVER )
	{
		float spd;
		float maxspeed;

		bool bIsOnSpeedPaint =  GetPortalPlayer()->GetPaintPower( SPEED_POWER ).m_State != INACTIVE_PAINT_POWER; //mv->m_flMaxSpeed > 150; // HACK: HL2_WALK_SPEED

		spd = ( mv->m_flForwardMove * mv->m_flForwardMove ) +
			  ( mv->m_flSideMove * mv->m_flSideMove ) +
			  ( mv->m_flUpMove * mv->m_flUpMove );

		maxspeed = mv->m_flClientMaxSpeed;
		if ( maxspeed != 0.0 )
		{
			mv->m_flMaxSpeed = MIN( maxspeed, mv->m_flMaxSpeed );
		}

		// Slow down by the speed factor
		float flSpeedFactor = 1.0f;
		if (player->m_pSurfaceData)
		{
			flSpeedFactor = player->m_pSurfaceData->game.maxSpeedFactor;
		}

		// If we have a constraint, slow down because of that too.
		float flConstraintSpeedFactor = ComputeConstraintSpeedFactor();
		if (flConstraintSpeedFactor < flSpeedFactor)
			flSpeedFactor = flConstraintSpeedFactor;

		mv->m_flMaxSpeed *= flSpeedFactor;

		float flSideMoveFactor = 1.0f;
		float flForwardMoveFactor = 1.0f;

		//If the player is on speed paint and pressing both a forward/backward and left/right movement keys
		if( bIsOnSpeedPaint && player->GetGroundEntity() &&
			mv->m_flForwardMove != 0.f && mv->m_flSideMove != 0.f )
		{
			const float flForwardSpeed = fabs( DotProduct( player->Forward(), mv->m_vecVelocity ) );
			const float flSideSpeed = fabs( DotProduct( player->Left(), mv->m_vecVelocity ) );

			// Figure out which direction we're more moving in: Side to side or forward/backward. then dampen our
			// input in the direction we're not mostly traveling
			if( flForwardSpeed > flSideSpeed )
			{
				flSideMoveFactor = sv_speed_paint_side_move_factor.GetFloat();
			}
			else
			{
				flForwardMoveFactor = sv_speed_paint_side_move_factor.GetFloat();
			}
		}

		// Go faster on speed paint
		if( bIsOnSpeedPaint )
		{
			float flSpeedPaintMultiplier = mv->m_flMaxSpeed / 150; // HACK: HL2_WALK_SPEED
			mv->m_flForwardMove *= flSpeedPaintMultiplier;
			mv->m_flSideMove    *= flSpeedPaintMultiplier;
			mv->m_flUpMove      *= flSpeedPaintMultiplier; // do we need this?
		}

		extern bool g_bMovementOptimizations;
		if ( g_bMovementOptimizations )
		{
			// Same thing but only do the sqrt if we have to.
			if ( ( spd != 0.0 ) && ( spd > mv->m_flMaxSpeed*mv->m_flMaxSpeed ) )
			{
				float fRatio = mv->m_flMaxSpeed / sqrt( spd );
				mv->m_flForwardMove *= fRatio;
				mv->m_flSideMove    *= fRatio;
				mv->m_flUpMove      *= fRatio;
			}
		}
		else
		{
			spd = sqrt( spd );
			if ( ( spd != 0.0 ) && ( spd > mv->m_flMaxSpeed ) )
			{
				float fRatio = mv->m_flMaxSpeed / spd;
				mv->m_flForwardMove *= fRatio;
				mv->m_flSideMove    *= fRatio;
				mv->m_flUpMove      *= fRatio;
			}
		}
	}

	if ( player->GetFlags() & FL_FROZEN ||
		 player->GetFlags() & FL_ONTRAIN || 
		 IsDead() )
	{
		mv->m_flForwardMove = 0;
		mv->m_flSideMove    = 0;
		mv->m_flUpMove      = 0;
	}

	DecayPunchAngle();

	// Take angles from command.
	if ( !IsDead() )
	{
		v_angle = mv->m_vecAngles;
		v_angle = v_angle + player->m_Local.m_vecPunchAngle;

		// Now adjust roll angle
		if ( player->GetMoveType() != MOVETYPE_ISOMETRIC  &&
			 player->GetMoveType() != MOVETYPE_NOCLIP )
		{
			mv->m_vecAngles[ROLL]  = CalcRoll( v_angle, mv->m_vecVelocity, sv_rollangle.GetFloat(), sv_rollspeed.GetFloat() );
		}
		else
		{
			mv->m_vecAngles[ROLL] = 0.0; // v_angle[ ROLL ];
		}
		mv->m_vecAngles[PITCH] = v_angle[PITCH];
		mv->m_vecAngles[YAW]   = v_angle[YAW];
	}
	else
	{
		mv->m_vecAngles = mv->m_vecOldAngles;
	}

	// Set dead player view_offset
	if ( IsDead() )
	{
		player->SetViewOffset( VEC_DEAD_VIEWHEIGHT_SCALED( player ) );
	}

	// Adjust client view angles to match values used on server.
	if ( mv->m_vecAngles[YAW] > 180.0f )
	{
		mv->m_vecAngles[YAW] -= 360.0f;
	}
}

void CPortalGameMovement::Duck( void )
{
	return BaseClass::Duck();
}

int CPortalGameMovement::CheckStuck( void )
{
	if( BaseClass::CheckStuck() )
	{
		CPortal_Player *pPortalPlayer = GetPortalPlayer();

#ifndef CLIENT_DLL
		if( pPortalPlayer->IsAlive() )
			g_PortalGameStats.Event_PlayerStuck( pPortalPlayer );
#endif

		//try to fix it, then recheck
		Vector vIndecisive;
		if( pPortalPlayer->m_hPortalEnvironment )
		{
			pPortalPlayer->m_hPortalEnvironment->GetVectors( &vIndecisive, NULL, NULL );
		}
		else
		{
			vIndecisive.Init( 0.0f, 0.0f, 1.0f );
		}
		Vector ptOldOrigin = pPortalPlayer->GetAbsOrigin();

		if( pPortalPlayer->m_hPortalEnvironment )
		{
			if( !FindClosestPassableSpace( pPortalPlayer, vIndecisive ) )
			{
#ifndef CLIENT_DLL
				DevMsg( "Hurting the player for FindClosestPassableSpaceFailure!" );

				CTakeDamageInfo info( pPortalPlayer, pPortalPlayer, vec3_origin, vec3_origin, 1e10, DMG_CRUSH );
				pPortalPlayer->OnTakeDamage( info );
#endif
			}

			//make sure we didn't get put behind the portal >_<
			Vector ptCurrentOrigin = pPortalPlayer->GetAbsOrigin();
			if( vIndecisive.Dot( ptCurrentOrigin - ptOldOrigin ) < 0.0f )
			{
				pPortalPlayer->SetAbsOrigin( ptOldOrigin + (vIndecisive * 5.0f) ); //this is an anti-bug hack, since this would have probably popped them out of the world, we're just going to move them forward a few units
			}
		}

		mv->SetAbsOrigin( pPortalPlayer->GetAbsOrigin() );
		return BaseClass::CheckStuck();
	}
	else
	{
		return 0;
	}
}

void CPortalGameMovement::SetGroundEntity( trace_t *pm )
{
#ifndef CLIENT_DLL
	if ( !player->GetGroundEntity() && pm && pm->m_pEnt )
	{
		IGameEvent *event = gameeventmanager->CreateEvent( "portal_player_touchedground" );
		if ( event )
		{
			event->SetInt( "userid", player->GetUserID() );
			gameeventmanager->FireEvent( event );
		}
	}
#endif
	
	CBaseEntity *newGround = pm ? pm->m_pEnt : NULL;

	//Adrian: Special case for combine balls.
	if ( newGround && newGround->GetCollisionGroup() == HL2COLLISION_GROUP_COMBINE_BALL_NPC )
	{
		return;
	}

	CBaseEntity *oldGround = player->GetGroundEntity();
	Vector vecBaseVelocity = player->GetBaseVelocity();

	if ( !oldGround && newGround )
	{
		// Subtract ground velocity at instant we hit ground jumping
		vecBaseVelocity -= newGround->GetAbsVelocity(); 
		vecBaseVelocity.z = newGround->GetAbsVelocity().z;
	}
	else if ( oldGround && !newGround )
	{
		// Add in ground velocity at instant we started jumping
 		vecBaseVelocity += oldGround->GetAbsVelocity();
		vecBaseVelocity.z = oldGround->GetAbsVelocity().z;
	}

	player->SetBaseVelocity( vecBaseVelocity );
	player->SetGroundEntity( newGround );

	// If we are on something...

	if ( newGround )
	{
		CategorizeGroundSurface( *pm );

		// Then we are not in water jump sequence
		player->m_flWaterJumpTime = 0;

		// Standing on an entity other than the world, so signal that we are touching something.
		if ( !pm->DidHitWorld() )
		{
			MoveHelper()->AddToTouched( *pm, mv->m_vecVelocity );
		}

		if( player->GetMoveType() != MOVETYPE_NOCLIP )
			mv->m_vecVelocity.z = 0.0f;
	}
}
#ifdef GAME_DLL
class CPortalMovementTraceFilter : public CTraceFilterSimple
{
public:
	CPortalMovementTraceFilter( const IHandleEntity *passentity, int collisionGroup, ShouldHitFunc_t pExtraShouldHitCheckFn = NULL ) 
		: CTraceFilterSimple( passentity, collisionGroup, pExtraShouldHitCheckFn ) {}

	virtual bool ShouldHitEntity( IHandleEntity *pEntity, int contentsMask )
	{
		CBaseEntity *pEnt = EntityFromEntityHandle( pEntity );
		if ( pEnt )
		{
			//const CPortal_Player *pPlayer = ToPortalPlayer( EntityFromEntityHandle( m_pPassEnt ) );
			IPhysicsObject *pObj = pEnt->VPhysicsGetObject();
			if ( /*pPlayer->m_bCatapulted &&*/ pObj && ( pObj->GetGameFlags() & FVPHYSICS_PLAYER_HELD ) )
			{
				return false;
			}
		}


		return CTraceFilterSimple::ShouldHitEntity( pEntity, contentsMask );
	}
};

#endif
void CPortalGameMovement::TracePlayerBBox( const Vector& start, const Vector& end, unsigned int fMask, int collisionGroup, trace_t& pm )
{
	VPROF( "CGameMovement::TracePlayerBBox" );
	
	CPortal_Player *pPortalPlayer = (CPortal_Player *)((CBaseEntity *)mv->m_nPlayerHandle.Get());

	Ray_t ray;
	ray.Init( start, end, GetPlayerMins(), GetPlayerMaxs() );

#ifdef CLIENT_DLL
	CTraceFilterSimple traceFilter( player, collisionGroup );
#else
	CTraceFilterSimple baseFilter( player, collisionGroup );
	CTraceFilterTranslateClones traceFilter( &baseFilter );
#endif

	UTIL_Portal_TraceRay_With( pPortalPlayer->m_hPortalEnvironment, ray, fMask, &traceFilter, &pm );

	// If we're moving through a portal and failed to hit anything with the above ray trace
	// Use UTIL_Portal_TraceEntity to test this movement through a portal and override the trace with the result
	if ( pm.fraction == 1.0f && UTIL_DidTraceTouchPortals( ray, pm ) && sv_player_trace_through_portals.GetBool() )
	{
		trace_t tempTrace;
		UTIL_Portal_TraceEntity( pPortalPlayer, start, end, fMask, &traceFilter, &tempTrace );

		if ( tempTrace.DidHit() && tempTrace.fraction < pm.fraction && !tempTrace.startsolid && !tempTrace.allsolid )
		{
			pm = tempTrace;
		}
	}
}

CBaseHandle CPortalGameMovement::TestPlayerPosition( const Vector& pos, int collisionGroup, trace_t& pm )
{
	TracePlayerBBox( pos, pos, MASK_PLAYERSOLID, collisionGroup, pm ); //hook into the existing portal special trace functionality

	//Ray_t ray;
	//ray.Init( pos, pos, GetPlayerMins(), GetPlayerMaxs() );
	//UTIL_TraceRay( ray, MASK_PLAYERSOLID, mv->m_nPlayerHandle.Get(), collisionGroup, &pm );
	if( pm.startsolid && pm.m_pEnt && (pm.contents & MASK_PLAYERSOLID) )
	{
#ifdef _DEBUG
		AssertMsgOnce( false, "The player got stuck on something. Break to investigate." ); //happens enough to just leave in a perma-debugger
		//this next trace is PURELY for tracking down how the player got stuck. Nothing new is discovered over the same trace about 10 lines up
        TracePlayerBBox( pos, pos, MASK_PLAYERSOLID, collisionGroup, pm );		
#endif
		return pm.m_pEnt->GetRefEHandle();
	}
#ifndef CLIENT_DLL
	else if ( pm.startsolid && pm.m_pEnt && CPSCollisionEntity::IsPortalSimulatorCollisionEntity( pm.m_pEnt ) )
	{
		// Stuck in a portal environment object, so unstick them!
		CPortal_Player *pPortalPlayer = (CPortal_Player *)((CBaseEntity *)mv->m_nPlayerHandle.Get());
		pPortalPlayer->SetStuckOnPortalCollisionObject();

		return INVALID_EHANDLE_INDEX;
	}
#endif
	else
	{	
		return INVALID_EHANDLE_INDEX;
	}
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CPortalGameMovement::FullWalkMove( )
{
	if ( !CheckWater() ) 
	{
		StartGravity();
	}

	// If we are leaping out of the water, just update the counters.
	if (player->m_flWaterJumpTime)
	{
		WaterJump();
		TryPlayerMove();
		// See if we are still in water?
		CheckWater();
		return;
	}

	// If we are swimming in the water, see if we are nudging against a place we can jump up out
	//  of, and, if so, start out jump.  Otherwise, if we are not moving up, then reset jump timer to 0
	if ( player->GetWaterLevel() >= WL_Waist ) 
	{
		if ( player->GetWaterLevel() == WL_Waist )
		{
			CheckWaterJump();
		}

			// If we are falling again, then we must not trying to jump out of water any more.
		if ( mv->m_vecVelocity[2] < 0 && 
			 player->m_flWaterJumpTime )
		{
			player->m_flWaterJumpTime = 0;
		}

		// Was jump button pressed?
		if (mv->m_nButtons & IN_JUMP)
		{
			CheckJumpButton();
		}
		else
		{
			mv->m_nOldButtons &= ~IN_JUMP;
		}

		// Perform regular water movement
		WaterMove();

		// Redetermine position vars
		CategorizePosition();

		// If we are on ground, no downward velocity.
		if ( player->GetGroundEntity() != NULL )
		{
			mv->m_vecVelocity[2] = 0;			
		}
	}
	else
	// Not fully underwater
	{
		// Was jump button pressed?
		if (mv->m_nButtons & IN_JUMP)
		{
 			CheckJumpButton();
		}
		else
		{
			mv->m_nOldButtons &= ~IN_JUMP;
		}

		// Fricion is handled before we add in any base velocity. That way, if we are on a conveyor, 
		//  we don't slow when standing still, relative to the conveyor.
		if (player->GetGroundEntity() != NULL)
		{
			mv->m_vecVelocity[2] = 0.0;
			player->m_Local.m_flFallVelocity = 0.0f;
			Friction();
		}

		// Make sure velocity is valid.
		CheckVelocity();
		
		CPortal_Player *pPortalPlayer = static_cast< CPortal_Player* >( player );
		if ( pPortalPlayer->GetTractorBeam() )
		{
			TBeamMove();
		}
		else
		{
			if (player->GetGroundEntity() != NULL)
			{
				WalkMove();
			}
			else
			{
				AirMove();  // Take into account movement when in air.
			}
		}

		// Set final flags.
		CategorizePosition();

		// Make sure velocity is valid.
		CheckVelocity();

		// Add any remaining gravitational component.
		if ( !CheckWater() )
		{
			FinishGravity();
		}

		// If we are on ground, no downward velocity.
		if ( player->GetGroundEntity() != NULL )
		{
			mv->m_vecVelocity[2] = 0;
		}
		CheckFalling();
	}

	if  ( ( m_nOldWaterLevel == WL_NotInWater && player->GetWaterLevel() != WL_NotInWater ) ||
		  ( m_nOldWaterLevel != WL_NotInWater && player->GetWaterLevel() == WL_NotInWater ) )
	{
		PlaySwimSound();
#if !defined( CLIENT_DLL )
		player->Splash();
#endif
	}
}


// Expose our interface.
static CPortalGameMovement g_GameMovement;
IGameMovement *g_pGameMovement = ( IGameMovement * )&g_GameMovement;

EXPOSE_SINGLE_INTERFACE_GLOBALVAR(CGameMovement, IGameMovement,INTERFACENAME_GAMEMOVEMENT, g_GameMovement );

