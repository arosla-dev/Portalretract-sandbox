//===== Copyright © 1996-2005, Valve Corporation, All rights reserved. ======//
//
// Purpose: 
//
// $NoKeywords: $
//
//===========================================================================//
#ifndef PORTAL_PLAYER_H
#define PORTAL_PLAYER_H
#pragma once

#include "portal_playeranimstate.h"
#include "c_basehlplayer.h"
#include "portal_player_shared.h"
#include "c_prop_portal.h"
#include "weapon_portalbase.h"
#include "c_func_liquidportal.h"
#include "colorcorrectionmgr.h"
#include "paint_power_user.h"
#include "paintable_entity.h"
#include "c_trigger_tractorbeam.h"

//=============================================================================
// >> Portal_Player
//=============================================================================
class C_Portal_Player : public PaintPowerUser< CPaintableEntity< C_BaseHLPlayer > >
{
public:
	DECLARE_CLASS( C_Portal_Player, PaintPowerUser< CPaintableEntity< C_BaseHLPlayer > > );

	DECLARE_CLIENTCLASS();
	DECLARE_PREDICTABLE();
	DECLARE_INTERPOLATION();


	C_Portal_Player();
	~C_Portal_Player( void );

	void ClientThink( void );
	void FixTeleportationRoll( void );

	static inline C_Portal_Player* GetLocalPortalPlayer()
	{
		return (C_Portal_Player*)C_BasePlayer::GetLocalPlayer();
	}

	static inline C_Portal_Player* GetLocalPlayer()
	{
		return (C_Portal_Player*)C_BasePlayer::GetLocalPlayer();
	}

	virtual const QAngle& GetRenderAngles();

	virtual void UpdateClientSideAnimation();
	void DoAnimationEvent( PlayerAnimEvent_t event, int nData );

	virtual int DrawModel( int flags, const RenderableInstance_t &instance );
	virtual bool PreRender( int nSplitScreenPlayerSlot );

	QAngle GetAnimEyeAngles( void ) { return m_angEyeAngles; }
	Vector GetAttackSpread( CBaseCombatWeapon *pWeapon, CBaseEntity *pTarget = NULL );

	// Used by prediction, sets the view angles for the player
	virtual void SetLocalViewAngles( const QAngle &viewAngles );
	virtual void SetViewAngles( const QAngle &ang );

	// Should this object cast shadows?
	virtual ShadowType_t	ShadowCastType( void );
	virtual C_BaseAnimating* BecomeRagdollOnClient();
	virtual bool			ShouldDraw( void );
	virtual const QAngle&	EyeAngles();
	virtual void			OnPreDataChanged( DataUpdateType_t type );
	virtual void			OnDataChanged( DataUpdateType_t type );
	bool					DetectAndHandlePortalTeleportation( void ); //detects if the player has portalled and fixes views
	virtual float			GetFOV( void );
	virtual CStudioHdr*		OnNewModel( void );
	virtual void			TraceAttack( const CTakeDamageInfo &info, const Vector &vecDir, trace_t *ptr );
	virtual void			ItemPreFrame( void );
	virtual void			ItemPostFrame( void );
	virtual float			GetMinFOV()	const { return 5.0f; }
	virtual Vector			GetAutoaimVector( float flDelta );
	virtual bool			ShouldReceiveProjectedTextures( int flags );
	virtual void			PostDataUpdate( DataUpdateType_t updateType );
	virtual void			GetStepSoundVelocities( float *velwalk, float *velrun );
	virtual void			SetStepSoundTime( stepsoundtimes_t iStepSoundTime, bool bWalking );
	virtual void			PlayStepSound( Vector &vecOrigin, surfacedata_t *psurface, float fvol, bool force );
	virtual void			PreThink( void );
	virtual void			PostThink( void );
	virtual void			DoImpactEffect( trace_t &tr, int nDamageType );

	virtual Vector			EyePosition();
	Vector					EyeFootPosition( const QAngle &qEyeAngles );//interpolates between eyes and feet based on view angle roll
	inline Vector			EyeFootPosition( void ) { return EyeFootPosition( EyeAngles() ); }; 
	void					PlayerPortalled( C_Prop_Portal *pEnteredPortal );

	virtual void	CalcView( Vector &eyeOrigin, QAngle &eyeAngles, float &zNear, float &zFar, float &fov );
	void			CalcPortalView( Vector &eyeOrigin, QAngle &eyeAngles );
	virtual void	CalcViewModelView( const Vector& eyeOrigin, const QAngle& eyeAngles);

	CBaseEntity*	FindUseEntity( void );
	CBaseEntity*	FindUseEntityThroughPortal( void );

	inline bool		IsCloseToPortal( void ) //it's usually a good idea to turn on draw hacks when this is true
	{
		return ((PortalEyeInterpolation.m_bEyePositionIsInterpolating) || (m_hPortalEnvironment.Get() != NULL));	
	} 

	bool	CanSprint( void );
	void	StartSprinting( void );
	void	StopSprinting( void );
	void	HandleSpeedChanges( void );
	void	UpdateLookAt( void );
	void	Initialize( void );
	int		GetIDTarget() const;
	void	UpdateIDTarget( void );

	void ToggleHeldObjectOnOppositeSideOfPortal( void ) { m_bHeldObjectOnOppositeSideOfPortal = !m_bHeldObjectOnOppositeSideOfPortal; }
	void SetHeldObjectOnOppositeSideOfPortal( bool p_bHeldObjectOnOppositeSideOfPortal ) { m_bHeldObjectOnOppositeSideOfPortal = p_bHeldObjectOnOppositeSideOfPortal; }
	bool IsHeldObjectOnOppositeSideOfPortal( void ) { return m_bHeldObjectOnOppositeSideOfPortal; }
	CProp_Portal *GetHeldObjectPortal( void ) { return m_pHeldObjectPortal; }

	Activity TranslateActivity( Activity baseAct, bool *pRequired = NULL );
	CWeaponPortalBase* GetActivePortalWeapon() const;
	
	bool IsSuppressingCrosshair( void ) { return m_bSuppressingCrosshair; }

private:

	C_Portal_Player( const C_Portal_Player & );

	void UpdatePortalEyeInterpolation( void );
	
	CPortalPlayerAnimState *m_PlayerAnimState;

	QAngle	m_angEyeAngles;
	CInterpolatedVar< QAngle >	m_iv_angEyeAngles;

	virtual IRagdoll		*GetRepresentativeRagdoll() const;
	EHANDLE	m_hRagdoll;

	int	m_headYawPoseParam;
	int	m_headPitchPoseParam;
	float m_headYawMin;
	float m_headYawMax;
	float m_headPitchMin;
	float m_headPitchMax;
	bool m_bSuppressingCrosshair;

	bool m_isInit;
	Vector m_vLookAtTarget;

	float m_flLastBodyYaw;
	float m_flCurrentHeadYaw;
	float m_flCurrentHeadPitch;
	float m_flStartLookTime;

	int	  m_iIDEntIndex;

	CountdownTimer m_blinkTimer;

	int	  m_iSpawnInterpCounter;
	int	  m_iSpawnInterpCounterCache;

	int	  m_iPlayerSoundType;

	bool  m_bHeldObjectOnOppositeSideOfPortal;
	CProp_Portal *m_pHeldObjectPortal;

	int	m_iForceNoDrawInPortalSurface; //only valid for one frame, used to temp disable drawing of the player model in a surface because of freaky artifacts

	struct PortalEyeInterpolation_t
	{
		bool	m_bEyePositionIsInterpolating; //flagged when the eye position would have popped between two distinct positions and we're smoothing it over
		Vector	m_vEyePosition_Interpolated; //we'll be giving the interpolation a certain amount of instant movement per frame based on how much an uninterpolated eye would have moved
		Vector	m_vEyePosition_Uninterpolated; //can't have smooth movement without tracking where we just were
		//bool	m_bNeedToUpdateEyePosition;
		//int		m_iFrameLastUpdated;

		int		m_iTickLastUpdated;
		float	m_fTickInterpolationAmountLastUpdated;
		bool	m_bDisableFreeMovement; //used for one frame usually when error in free movement is likely to be high
		bool	m_bUpdatePosition_FreeMove;

		PortalEyeInterpolation_t( void ) : m_iTickLastUpdated(0), m_fTickInterpolationAmountLastUpdated(0.0f), m_bDisableFreeMovement(false), m_bUpdatePosition_FreeMove(false) { };
	} PortalEyeInterpolation;

	struct PreDataChanged_Backup_t
	{
		CHandle<C_Prop_Portal>	m_hPortalEnvironment;
		CHandle<C_Func_LiquidPortal>	m_hSurroundingLiquidPortal;
		//Vector					m_ptPlayerPosition;
		QAngle					m_qEyeAngles;
	} PreDataChanged_Backup;

	Vector	m_ptEyePosition_LastCalcView;
	QAngle	m_qEyeAngles_LastCalcView; //we've got some VERY persistent single frame errors while teleporting, this will be updated every frame in CalcView() and will serve as a central source for fixed angles
	C_Prop_Portal *m_pPortalEnvironment_LastCalcView;

	ClientCCHandle_t	m_CCDeathHandle;	// handle to death cc effect
	float				m_flDeathCCWeight;	// for fading in cc effect	

	bool	m_bPortalledMessagePending; //Player portalled. It's easier to wait until we get a OnDataChanged() event or a CalcView() before we do anything about it. Otherwise bits and pieces can get undone
	VMatrix m_PendingPortalMatrix;

	CHandle<C_Trigger_TractorBeam> m_hTractorBeam;
	int m_nTractorBeamCount;

	// PAINT POWER STATE
	PaintPowerInfo_t m_CachedJumpPower;
	Vector m_vInputVector;
	float m_flCachedJumpPowerTime;
	float m_flSpeedDecelerationTime;
	float m_flPredictedJumpTime;

	InAirState m_InAirState;
	PaintPowerType m_PaintedPowerType;
	Vector m_vPreUpdateVelocity;
	bool m_bJumpedThisFrame;
	bool m_bBouncedThisFrame;
	CountdownTimer m_PaintedPowerTimer;
	CachedPaintPowerChoiceResult m_CachedPaintPowerChoiceResults[PAINT_POWER_TYPE_COUNT];
	float m_fBouncedTime;

	Vector m_vPrevGroundNormal;	// Our ground normal from the previous frame

public:
	
	Vector GetPaintGunShootPosition();

	bool	m_bPitchReorientation;
	float	m_fReorientationRate;
	bool	m_bEyePositionIsTransformedByPortal; //when the eye and body positions are not on the same side of a portal

	CHandle<C_Prop_Portal>	m_hPortalEnvironment; //a portal whose environment the player is currently in, should be invalid most of the time
	CHandle<C_Func_LiquidPortal>	m_hSurroundingLiquidPortal; //a liquid portal whose volume the player is standing in
	
	void SetInTractorBeam( C_Trigger_TractorBeam *pTractorBeam );
	void SetLeaveTractorBeam( C_Trigger_TractorBeam *pTractorBeam, bool bKeepFloating );
	C_Trigger_TractorBeam* GetTractorBeam( void ) const { return m_hTractorBeam.Get(); }
	
	const Vector& GetPrevGroundNormal() const;
	void SetPrevGroundNormal( const Vector& vPrevNormal );

public: // Paint

	void OnBounced( float fTimeOffset = 0.0f );

	virtual void ChooseActivePaintPowers( PaintPowerInfoVector& activePowers );
	
	using BaseClass::AddSurfacePaintPowerInfo;
	void AddSurfacePaintPowerInfo( const BrushContact& contact, char const* context = 0 );
	void AddSurfacePaintPowerInfo( const trace_t& trace, char const* context = 0 );

	// Find all the contacts
	void DeterminePaintContacts();
	void PredictPaintContacts( const Vector& contactBoxMin,
		const Vector& contactBoxMax,
		const Vector& traceBoxMin,
		const Vector& traceBoxMax,
		float lookAheadTime,
		char const* context );
	void ChooseBestPaintPowersInRange( PaintPowerChoiceResultArray& bestPowers,
		PaintPowerConstIter begin,
		PaintPowerConstIter end,
		const PaintPowerChoiceCriteria_t& info ) const;

	// Paint Power User Implementation
	virtual PaintPowerState ActivateSpeedPower( PaintPowerInfo_t& powerInfo );
	virtual PaintPowerState UseSpeedPower( PaintPowerInfo_t& powerInfo );
	virtual PaintPowerState DeactivateSpeedPower( PaintPowerInfo_t& powerInfo );

	virtual PaintPowerState ActivateBouncePower( PaintPowerInfo_t& powerInfo );
	virtual PaintPowerState UseBouncePower( PaintPowerInfo_t& powerInfo );
	virtual PaintPowerState DeactivateBouncePower( PaintPowerInfo_t& powerInfo );

	//void PlayPaintSounds( const PaintPowerChoiceResultArray& touchedPowers );
	void UpdatePaintedPower();
	void UpdateAirInputScaleFadeIn();
	void UpdateInAirState();
	void CachePaintPowerChoiceResults( const PaintPowerChoiceResultArray& choiceInfo );
	bool LateSuperJumpIsValid() const;

	virtual PaintPowerType GetPaintPowerAtPoint( const Vector& worldContactPt ) const;
	virtual void Paint( PaintPowerType type, const Vector& worldContactPt );
	virtual void CleansePaint();

	// Paint power debug
	void DrawJumpHelperDebug( PaintPowerConstIter begin, PaintPowerConstIter end, float duration, bool noDepthTest, const PaintPowerInfo_t* pSelected ) const;

	float SpeedPaintAcceleration( float flDefaultMaxSpeed,
								  float flSpeed,
								  float flWishCos,
								  float flWishDirSpeed ) const;

	bool CheckToUseBouncePower( PaintPowerInfo_t& info );

	bool IsPressingJumpKey() const;
	bool IsHoldingJumpKey() const;
	bool IsTryingToSuperJump( const PaintPowerInfo_t* pInfo = NULL ) const;
	void SetJumpedThisFrame( bool jumped );
	bool JumpedThisFrame() const;
	void SetBouncedThisFrame( bool bounced );
	bool BouncedThisFrame() const;
	InAirState GetInAirState() const;

	const Vector& GetInputVector() const;
	void SetInputVector( const Vector& vInput );
};

inline C_Portal_Player *ToPortalPlayer( CBaseEntity *pEntity )
{
	if ( !pEntity || !pEntity->IsPlayer() )
		return NULL;

	return dynamic_cast<C_Portal_Player*>( pEntity );
}

inline C_Portal_Player *GetPortalPlayer( void )
{
	return static_cast<C_Portal_Player*>( C_BasePlayer::GetLocalPlayer() );
}

#endif //Portal_PLAYER_H
