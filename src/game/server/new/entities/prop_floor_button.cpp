//===== Copyright (c) 1996-2005, Valve Corporation, All rights reserved. ======//
//
//  Purpose: button that can be pressed by a weighted cube or player standing on it
//
//===========================================================================//

#include "cbase.h"
#include "props.h"
#include "triggers.h"
#include "portal/prop_weighted_cube.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

#define PROP_FLOOR_BUTTON_DEFAULT_MODEL_NAME "models/props/portal_button.mdl"

#define BUTTON_SOUND_PRESSED "sound/buttons/button3.wav"

static const char* s_pszPressingBoxHasSetteledThinkContext = "PressingBoxHasSetteledThinkContext";

class CPropFloorButton;

enum button_skins
{
	button_off_skin,
	button_on_skin
};

//
// Trigger for floor button
//

class CPortalButtonTrigger : public CBaseTrigger
{
public:
	DECLARE_CLASS(CPortalButtonTrigger, CBaseTrigger);
	DECLARE_DATADESC();

	static CPortalButtonTrigger* Create(const Vector& vecOrigin, const QAngle& vecAngles, const Vector& vecMins, const Vector& vecMaxs, CPropFloorButton* pOwner);

	virtual bool PassesTriggerFilters(CBaseEntity* pOther);

	virtual void OnStartTouchAll(CBaseEntity* pOther);

	virtual void EndTouch(CBaseEntity* pOther);
	virtual void OnEndTouchAll(CBaseEntity* pOther);
	virtual void StartTouch(CBaseEntity* pOther);
	virtual void Spawn(void);


private:
	CPropFloorButton* m_pOwnerButton;
};

LINK_ENTITY_TO_CLASS(trigger_portal_button, CPortalButtonTrigger);

BEGIN_DATADESC(CPortalButtonTrigger)

DEFINE_FIELD(m_pOwnerButton, FIELD_CLASSPTR),

END_DATADESC()

//
// Floor Button
//

class CPropFloorButton : public CDynamicProp
{
public:
	DECLARE_CLASS(CPropFloorButton, CDynamicProp);
	DECLARE_DATADESC();
	DECLARE_SERVERCLASS();

	CPropFloorButton();

	virtual void Precache(void);
	virtual void Spawn(void);
	virtual bool CreateVPhysics(void);
	virtual void Activate(void);

	virtual void AnimateThink(void);
	virtual void UpdateOnRemove(void);
	void PressingBoxHasSetteledThink(void);

	virtual bool ShouldPlayerTouch();
	virtual bool OnlyAcceptBall(void) { return false; }
	virtual bool AcceptsBall(void) { return true; }
	void	SetSkin(int skinNum);

private:
	void OnPressed(CBaseEntity* pActivator);
	void OnUnPressed(CBaseEntity* pActivator);

	COutputEvent					m_OnPressed;
	COutputEvent					m_OnPressedOrange;
	COutputEvent					m_OnPressedBlue;
	COutputEvent					m_OnUnPressed;

protected:
	CHandle<CPortalButtonTrigger>	m_hButtonTrigger;

	CNetworkVar(bool, m_bButtonState);

	virtual void CreateTriggers(void);
	void TriggerStartTouch(CBaseEntity* pOther);
	void TriggerEndTouch(CBaseEntity* pOther);

	virtual void Press(CBaseEntity* pActivator);
	virtual void UnPress(CBaseEntity* pActivator);

	void InputPressIn(inputdata_t& inputdata);
	void InputPressOut(inputdata_t& inputdata);

	virtual void LookUpAnimationSequences(void);

	// animation sequences for the button
	int								m_UpSequence;
	int								m_DownSequence;

	friend class CPortalButtonTrigger;
};

LINK_ENTITY_TO_CLASS(prop_floor_button, CPropFloorButton);

BEGIN_DATADESC(CPropFloorButton)

DEFINE_THINKFUNC(AnimateThink),
DEFINE_THINKFUNC(PressingBoxHasSetteledThink),

DEFINE_FIELD(m_UpSequence, FIELD_INTEGER),
DEFINE_FIELD(m_DownSequence, FIELD_INTEGER),

DEFINE_FIELD(m_hButtonTrigger, FIELD_EHANDLE),

DEFINE_INPUTFUNC(FIELD_VOID, "PressIn", InputPressIn),
DEFINE_INPUTFUNC(FIELD_VOID, "PressOut", InputPressOut),

DEFINE_OUTPUT(m_OnPressed, "OnPressed"),
DEFINE_OUTPUT(m_OnPressedOrange, "OnPressedOrange"),
DEFINE_OUTPUT(m_OnPressedBlue, "OnPressedBlue"),
DEFINE_OUTPUT(m_OnUnPressed, "OnUnPressed"),

END_DATADESC()

IMPLEMENT_SERVERCLASS_ST(CPropFloorButton, DT_PropFloorButton)

SendPropBool(SENDINFO(m_bButtonState)),

END_SEND_TABLE()

//-----------------------------------------------------------------------------
// Purpose: constructor
//-----------------------------------------------------------------------------
CPropFloorButton::CPropFloorButton() : m_bButtonState(false) // button is not pressed by default
{
	
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CPropFloorButton::Precache(void)
{
	PrecacheModel("models/props/portal_button.mdl");

	PrecacheScriptSound("Portal.button_down");
	PrecacheScriptSound("Portal.button_up");

	BaseClass::Precache();
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CPropFloorButton::Spawn(void)
{
	Precache();
	SetModel("models/props/portal_button.mdl");

	BaseClass::Spawn();

	SetSolid(SOLID_VPHYSICS);

	LookUpAnimationSequences();

	// Start in the up state
	ResetSequence(m_UpSequence);

	//Buttons are unpaintable
	AddFlag(FL_UNPAINTABLE);

	CreateVPhysics();

	CreateTriggers();

	// Never let crucial game components fade out!
	SetFadeDistance(-1.0f, 0.0f);
	SetGlobalFadeScale(0.0f);
}


void CPropFloorButton::LookUpAnimationSequences(void)
{
	// look up animation sequences
	m_UpSequence = LookupSequence("up");
	m_DownSequence = LookupSequence("down");
}


bool CPropFloorButton::CreateVPhysics(void)
{
	BaseClass::CreateVPhysics();
	return true;
}

void CPropFloorButton::Activate(void)
{
	BaseClass::Activate();

	SetThink(&CPropFloorButton::AnimateThink);
	SetNextThink(gpGlobals->curtime + 0.1f);
}

//-----------------------------------------------------------------------------
// Purpose: Animate and catch edge cases for us stopping / starting our animation
//-----------------------------------------------------------------------------
void CPropFloorButton::AnimateThink(void)
{
	// Update our animation
	StudioFrameAdvance();
	DispatchAnimEvents(this);
	m_BoneFollowerManager.UpdateBoneFollowers(this);

	SetNextThink(gpGlobals->curtime + 0.1f);

	// debug overlay of trigger displays if ent_bbox is used on entity
	if (m_debugOverlays & OVERLAY_BBOX_BIT)
	{
		if (m_hButtonTrigger)
		{
			m_hButtonTrigger->m_debugOverlays |= OVERLAY_BBOX_BIT;
			NDebugOverlay::Cross3D(GetAbsOrigin(), 4, 0, 255, 0, true, 0.1f);
		}
	}
	else
	{
		if (m_hButtonTrigger)
		{
			m_hButtonTrigger->m_debugOverlays &= ~OVERLAY_BBOX_BIT;
		}
	}
}

void CPropFloorButton::PressingBoxHasSetteledThink(void)
{
	SetContextThink(NULL, gpGlobals->curtime, s_pszPressingBoxHasSetteledThinkContext);
}

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
void CPropFloorButton::UpdateOnRemove(void)
{
	if (m_hButtonTrigger)
	{
		UTIL_Remove(m_hButtonTrigger);
		m_hButtonTrigger = NULL;
	}
	BaseClass::UpdateOnRemove();
}

//-----------------------------------------------------------------------------
// Purpose: Press the button
//-----------------------------------------------------------------------------
void CPropFloorButton::Press(CBaseEntity* pActivator)
{
	// play the down sequence
	ResetSequence(m_DownSequence);

	// set the button state for the client
	m_bButtonState = true;

	// Change the skin
	SetSkin(button_on_skin);

	// call the function that fires the OnPressed output
	OnPressed(pActivator);
	EmitSound("Portal.button_down");
}

//-----------------------------------------------------------------------------
// Purpose: UnPress the button
//-----------------------------------------------------------------------------
void CPropFloorButton::UnPress(CBaseEntity* pActivator)
{
	// play the up sequence
	ResetSequence(m_UpSequence);

	// set the button state for the client
	m_bButtonState = false;

	// Change the skin
	SetSkin(button_off_skin);

	// call the function that fires the OnUnPressed output
	OnUnPressed(pActivator);
	EmitSound("Portal.button_up");
}

void CPropFloorButton::InputPressIn(inputdata_t& inputdata)
{
	Press(inputdata.pActivator);
}

void CPropFloorButton::InputPressOut(inputdata_t& inputdata)
{
	UnPress(inputdata.pActivator);
}

//-----------------------------------------------------------------------------
// Purpose: Fire output for button being pressed
//-----------------------------------------------------------------------------
void CPropFloorButton::OnPressed(CBaseEntity* pActivator)
{

	// If this button was pressed without touching the player, fire the special output used for the 'hole in one' achievement.
	if (UTIL_IsWeightedCube(pActivator))
	{
		CPropWeightedCube* pCube = (CPropWeightedCube*)pActivator;
		Assert(pCube);
		if (pCube)
		{

			// HACK: this delay is a guess at how long it takes to be sure the box has setteled... 
			SetContextThink(&CPropFloorButton::PressingBoxHasSetteledThink, gpGlobals->curtime + 2.0f, s_pszPressingBoxHasSetteledThinkContext);
			
		}
	}

	m_OnPressed.FireOutput(pActivator, this);
}

//-----------------------------------------------------------------------------
// Purpose: Fire output when button has reset after being pressed
//-----------------------------------------------------------------------------
void CPropFloorButton::OnUnPressed(CBaseEntity* pActivator)
{
	SetContextThink(NULL, gpGlobals->curtime, s_pszPressingBoxHasSetteledThinkContext);

	// fire the OnUnPressed output
	m_OnUnPressed.FireOutput(pActivator, this);
}

//-----------------------------------------------------------------------------
// Purpose: Create triggers for button
//-----------------------------------------------------------------------------
void CPropFloorButton::CreateTriggers(void)
{
	Vector vecOrigin = GetAbsOrigin();

	// trigger size
	Vector vecMins(-20, -20, 0);
	Vector vecMaxs(20, 20, 14);


	// Create the button trigger
	m_hButtonTrigger = CPortalButtonTrigger::Create(vecOrigin, GetAbsAngles(), vecMins, vecMaxs, this);
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CPropFloorButton::TriggerStartTouch(CBaseEntity* pOther)
{
	Press(pOther);
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CPropFloorButton::TriggerEndTouch(CBaseEntity* pOther)
{
	UnPress(pOther);
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
bool CPropFloorButton::ShouldPlayerTouch()
{
	// Yes, players can touch the prop floor button
	return true;
}

//-----------------------------------------------------------------------------
// Purpose: Set the model skin
//-----------------------------------------------------------------------------
void CPropFloorButton::SetSkin(int skinNum)
{
	m_nSkin = skinNum;
}

//-----------------------------------------------------------------------------
// Purpose: creates the button trigger
//-----------------------------------------------------------------------------
CPortalButtonTrigger* CPortalButtonTrigger::Create(const Vector& vecOrigin, const QAngle& vecAngles, const Vector& vecMins, const Vector& vecMaxs, CPropFloorButton* pOwner)
{
	CPortalButtonTrigger* pTrigger = (CPortalButtonTrigger*)CreateEntityByName("trigger_portal_button");
	if (pTrigger == NULL)
		return NULL;

	UTIL_SetOrigin(pTrigger, vecOrigin);
	pTrigger->SetAbsAngles(vecAngles);
	UTIL_SetSize(pTrigger, vecMins, vecMaxs);

	DispatchSpawn(pTrigger);

	pTrigger->SetParent((CBaseEntity*)pOwner);

	pTrigger->m_pOwnerButton = pOwner;

	return pTrigger;
}

void CPortalButtonTrigger::StartTouch(CBaseEntity* pOther)
{
	BaseClass::StartTouch(pOther);
}

void CPortalButtonTrigger::EndTouch(CBaseEntity* pOther)
{
	BaseClass::EndTouch(pOther);
}

//----------------------------------------------------------------------------------
// Purpose: checks filters on trigger in addition to specific filters (player, cube)
//----------------------------------------------------------------------------------
bool CPortalButtonTrigger::PassesTriggerFilters(CBaseEntity* pOther)
{
	bool bPassedFilter = BaseClass::PassesTriggerFilters(pOther);

	// did I fail the baseclass filter check?
	if (!bPassedFilter)
		return false;


	// are players allowed to touch me?
	if (m_pOwnerButton->ShouldPlayerTouch())
	{
		// did a player touch me?
		if (pOther->IsPlayer())
			return true;
	}

	// did a cube touch me?
	if (FClassnameIs(pOther, "prop_weighted_cube") || FClassnameIs(pOther, "prop_physics"))
	{
		CPropWeightedCube* pCube = static_cast<CPropWeightedCube*>(pOther);
		bool bIsBall = pCube && pCube->GetCubeType() == CUBE_SPHERE;

		if ((bIsBall && m_pOwnerButton->AcceptsBall()) || //If the button accepts balls and this is a ball ( floor, under and ball buttons )
			(!bIsBall && !m_pOwnerButton->OnlyAcceptBall())) //If the button doesn't only accept balls and this is not a ball ( cube buttons )
		{
			return true;
		}
	}

	// failed filter check
	return false;
}

//----------------------------------------------------------------------------------
// Purpose: called only when the trigger is touched for the first time
//----------------------------------------------------------------------------------
void CPortalButtonTrigger::OnStartTouchAll(CBaseEntity* pOther)
{
	// call the button's start touch function
	if (m_pOwnerButton)
	{
		m_pOwnerButton->TriggerStartTouch(pOther);
	}

	BaseClass::OnStartTouchAll(pOther);
}

//----------------------------------------------------------------------------------
// Purpose: called when the last object stops touching the trigger
//----------------------------------------------------------------------------------
void CPortalButtonTrigger::OnEndTouchAll(CBaseEntity* pOther)
{
	// call the button's end touch function
	if (m_pOwnerButton)
	{
		m_pOwnerButton->TriggerEndTouch(pOther);
	}

	BaseClass::OnEndTouchAll(pOther);
}

//----------------------------------------------------------------------------------
// Purpose: spawn the trigger
//----------------------------------------------------------------------------------
void CPortalButtonTrigger::Spawn(void)
{
	// Setup our basic attributes
	SetMoveType(MOVETYPE_NONE);
	SetSolid(SOLID_OBB);
	SetSolidFlags(FSOLID_NOT_SOLID | FSOLID_TRIGGER);

	AddSpawnFlags(SF_TRIGGER_ALLOW_CLIENTS | SF_TRIGGER_ALLOW_PHYSICS);

	BaseClass::Spawn();
}