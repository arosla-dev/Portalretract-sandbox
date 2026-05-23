//========= Copyright Valve Corporation, All rights reserved. ============//
// tf_bot_payload_guard.cpp
// Guard the payload and keep the attackers from getting near it
// Michael Booth, April 2010

#include "cbase.h"
#include "nav_mesh.h"
#include "tf_player.h"
#include "tf_gamerules.h"
#include "team_control_point_master.h"
#include "team_train_watcher.h"
#include "trigger_area_capture.h"
#include "bot/tf_bot.h"
#include "bot/behavior/scenario/payload/tf_bot_payload_guard.h"
#include "bot/behavior/scenario/payload/tf_bot_payload_block.h"
#include "bot/behavior/medic/tf_bot_medic_heal.h"
#include "bot/behavior/engineer/tf_bot_engineer_build.h"
#include "bot/behavior/demoman/tf_bot_prepare_stickybomb_trap.h"


extern ConVar tf_bot_path_lookahead_range;

ConVar tf_bot_payload_guard_range( "tf_bot_payload_guard_range", "1000", FCVAR_CHEAT );
ConVar tf_bot_debug_payload_guard_vantage_points( "tf_bot_debug_payload_guard_vantage_points", 0, FCVAR_CHEAT );


//---------------------------------------------------------------------------------------------
ActionResult< CTFBot >	CTFBotPayloadGuard::OnStart( CTFBot *me, Action< CTFBot > *priorAction )
{
	m_path.SetMinLookAheadDistance( me->GetDesiredPathLookAheadRange() );
	m_path.Invalidate();

	m_vantagePoint = me->GetAbsOrigin();

	return Continue();
}


//---------------------------------------------------------------------------------------------
ActionResult< CTFBot >	CTFBotPayloadGuard::Update( CTFBot *me, float interval )
{
	const CKnownEntity *threat = me->GetVisionInterface()->GetPrimaryKnownThreat();
	if ( threat && threat->IsVisibleRecently() )
	{
		// prepare to fight
		me->EquipBestWeaponForThreat( threat );
	}

	if ( m_moveToBlockTimer.HasStarted() && m_moveToBlockTimer.IsElapsed() )
	{
		m_moveToBlockTimer.Invalidate();
	}

	bool isMovingToVantagePoint = ( me->GetAbsOrigin() - m_vantagePoint ).AsVector2D().IsLengthGreaterThan( 25.0f );

	if ( isMovingToVantagePoint )
	{
		// en route, don't change the point
		m_vantagePointTimer.Start( RandomFloat( 3.0f, 15.0f ) );
	}

	if ( isMovingToVantagePoint )
	{
		// update our path periodically
		if ( m_repathTimer.IsElapsed() )
		{
			CTFBotPathCost cost( me, DEFAULT_ROUTE );
			m_path.Compute( me, m_vantagePoint, cost );
			m_repathTimer.Start( RandomFloat( 0.5f, 1.0f ) );
		}

		// move towards our vantage point
		m_path.Update( me );
	}
	else
	{
		// at vantage point
		if ( CTFBotPrepareStickybombTrap::IsPossible( me ) )
		{
			return SuspendFor( new CTFBotPrepareStickybombTrap, "Laying sticky bombs!" );
		}
	}

	return Continue();
}


//---------------------------------------------------------------------------------------------
ActionResult< CTFBot > CTFBotPayloadGuard::OnResume( CTFBot *me, Action< CTFBot > *interruptingAction )
{
	VPROF_BUDGET( "CTFBotPayloadGuard::OnResume", "NextBot" );

	m_vantagePointTimer.Invalidate();
	m_repathTimer.Invalidate();

	return Continue();
}


//---------------------------------------------------------------------------------------------
EventDesiredResult< CTFBot > CTFBotPayloadGuard::OnStuck( CTFBot *me )
{
	VPROF_BUDGET( "CTFBotPayloadGuard::OnStuck", "NextBot" );

	m_repathTimer.Invalidate();
	me->GetLocomotionInterface()->ClearStuckStatus();

	return TryContinue();
}


//---------------------------------------------------------------------------------------------
EventDesiredResult< CTFBot > CTFBotPayloadGuard::OnMoveToSuccess( CTFBot *me, const Path *path )
{
	return TryContinue();
}


//---------------------------------------------------------------------------------------------
EventDesiredResult< CTFBot > CTFBotPayloadGuard::OnMoveToFailure( CTFBot *me, const Path *path, MoveToFailureType reason )
{
	VPROF_BUDGET( "CTFBotPayloadGuard::OnMoveToFailure", "NextBot" );

	m_vantagePointTimer.Invalidate();
	m_repathTimer.Invalidate();

	return TryContinue();
}


//---------------------------------------------------------------------------------------------
// Invoked when cart is being pushed
EventDesiredResult< CTFBot > CTFBotPayloadGuard::OnTerritoryContested( CTFBot *me, int territoryID )
{
	return TryContinue();
}


//---------------------------------------------------------------------------------------------
EventDesiredResult< CTFBot > CTFBotPayloadGuard::OnTerritoryCaptured( CTFBot *me, int territoryID )
{
	return TryContinue();
}


//---------------------------------------------------------------------------------------------
// Invoked when cart hits a checkpoint
EventDesiredResult< CTFBot > CTFBotPayloadGuard::OnTerritoryLost( CTFBot *me, int territoryID )
{
	return TryContinue();
}


//---------------------------------------------------------------------------------------------
QueryResultType	CTFBotPayloadGuard::ShouldRetreat( const INextBot *bot ) const
{

	return ANSWER_UNDEFINED;
}


//---------------------------------------------------------------------------------------------
QueryResultType CTFBotPayloadGuard::ShouldHurry( const INextBot *bot ) const
{
	return ANSWER_UNDEFINED;
}


//---------------------------------------------------------------------------------------------
class CCollectPayloadGuardVantagePoints : public ISearchSurroundingAreasFunctor
{
public:
	CCollectPayloadGuardVantagePoints( CTFBot *me, CBaseEntity *cart )
	{
		m_me = me;
		m_cart = cart;
	}

	virtual bool operator() ( CNavArea *baseArea, CNavArea *priorArea, float travelDistanceSoFar )
	{
		CTFNavArea *area = (CTFNavArea *)baseArea;

		// TODO: only use areas that are at/farther along than the payload

		trace_t trace;
		NextBotTraceFilterIgnoreActors filter( NULL, COLLISION_GROUP_NONE );

		const int tryCount = 3;

		for( int i=0; i<tryCount; ++i )
		{
			Vector spot = area->GetRandomPoint();
			Vector eyeSpot = Vector( spot.x, spot.y, spot.z + HumanEyeHeight );

			UTIL_TraceLine( eyeSpot, m_cart->WorldSpaceCenter(), MASK_SOLID_BRUSHONLY, &filter, &trace );

			if ( !trace.DidHit() || trace.m_pEnt == m_cart )
			{
				m_vantagePointVector.AddToTail( spot );

				if ( tf_bot_debug_payload_guard_vantage_points.GetBool() )
				{
					NDebugOverlay::Cross3D( spot, 5.0f, 255, 0, 255, true, 120.0f );
				}
			}
		}

		return true;
	}

	CTFBot *m_me;
	CBaseEntity *m_cart;
	CUtlVector< Vector > m_vantagePointVector;
};


//---------------------------------------------------------------------------------------------
//
// Find a tactically advantageous area where we can see the payload
//
Vector CTFBotPayloadGuard::FindVantagePoint( CTFBot *me, CBaseEntity *cart )
{

	CCollectPayloadGuardVantagePoints collect( me, cart );
	if ( collect.m_vantagePointVector.Count() == 0 )
		return cart->WorldSpaceCenter();

	int which = RandomInt( 0, collect.m_vantagePointVector.Count()-1 );
	return collect.m_vantagePointVector[ which ];
}

