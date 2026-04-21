//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:		Basic Icegun Recreation
//
// $NoKeywords: $
//=============================================================================//

#include "cbase.h"
#include "npcevent.h"
#include "basehlcombatweapon.h"
#include "basecombatcharacter.h"
#include "ai_basenpc.h"
#include "player.h"
#include "gamerules.h"
#include "in_buttons.h"
#include "soundent.h"
#include "game.h"
#include "vstdlib/random.h"
#include "engine/IEngineSound.h"
#include "te_effect_dispatch.h"
#include "gamestats.h"
#include "particle_parse.h"
// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

ConVar icegun_freeze_scale("icegun_freeze_scale","0.1");

//-----------------------------------------------------------------------------
// CWeaponIcegun
//-----------------------------------------------------------------------------

class CWeaponIcegun : public CBaseHLCombatWeapon
{
	DECLARE_CLASS(CWeaponIcegun, CBaseHLCombatWeapon);
public:
	DECLARE_SERVERCLASS();

	CWeaponIcegun(void);
	void	PrimaryAttack(void);
	void	ItemPostFrame();
	void	Precache();
	void	Spawn();
	virtual bool	IsSpecialSuitAbility()
	{//We are a special suit ability
		return true;
	}

	DECLARE_DATADESC();

	CNetworkVector(m_targetPosition);
	CNetworkVector(m_worldPosition);
	CNetworkVar(int,m_active);
	CNetworkVar(int, m_viewModelIndex);
};


LINK_ENTITY_TO_CLASS(weapon_icegun, CWeaponIcegun);

PRECACHE_WEAPON_REGISTER(weapon_icegun);

BEGIN_DATADESC(CWeaponIcegun)
END_DATADESC()

IMPLEMENT_SERVERCLASS_ST(CWeaponIcegun, DT_WeaponIcegun)
SendPropVector(SENDINFO(m_targetPosition)),
SendPropVector(SENDINFO(m_worldPosition)),
SendPropInt(SENDINFO(m_active)),
SendPropInt(SENDINFO(m_viewModelIndex)),
END_SEND_TABLE()

bool Icegun_IsPlayerIceSurfing()
{
	return false;
}


CWeaponIcegun::CWeaponIcegun(void)
{
	m_bReloadsSingly = false;
	m_bFiresUnderwater = false;
}

void CWeaponIcegun::Precache()
{
	BaseClass::Precache();
}

void CWeaponIcegun::Spawn()
{
	Precache();

	BaseClass::Spawn();
}

void CWeaponIcegun::ItemPostFrame()
{
	CBasePlayer* pOwner = ToBasePlayer(GetOwner());
	if (pOwner == NULL)
	{
		return;
	}

	if ((pOwner->m_nButtons & IN_ATTACK))// && (m_flNextPrimaryAttack <= gpGlobals->curtime))
	{
		PrimaryAttack();
	}
	else
	{
		m_active = false;
	}
}

void CWeaponIcegun::PrimaryAttack(void)
{
	CBasePlayer* pOwner = ToBasePlayer(GetOwner());
	if (!pOwner)
		return;

	m_viewModelIndex = pOwner->entindex();
	// Make sure I've got a view model
	CBaseViewModel* vm = pOwner->GetViewModel();
	if (vm)
	{
		m_viewModelIndex = vm->entindex();
	}

	Vector vecDir;
	AngleVectors(pOwner->EyeAngles(), &vecDir);

	Vector vecAbsStart = pOwner->EyePosition();
	Vector vecAbsEnd = vecAbsStart + (vecDir * MAX_TRACE_LENGTH);

	Ray_t ray;
	ray.Init(vecAbsStart, vecAbsEnd);

	trace_t tr;
	UTIL_TraceRay(ray, MASK_ALL, pOwner, COLLISION_GROUP_NONE, &tr);

	if (tr.DidHit())
	{
		if (tr.m_pEnt && tr.m_pEnt->GetBaseAnimating() && !FClassnameIs(tr.m_pEnt,"physics_prop_statue"))//Hack to prevent npcs that were just frozen from disappearing immediately
		{
			//Probably should check if npcs are friendly like the other weapon code.
			CBaseAnimating * entity = tr.m_pEnt->GetBaseAnimating();
			entity->Freeze(icegun_freeze_scale.GetFloat(), pOwner, &ray);
		}
		m_targetPosition = tr.endpos;
		m_worldPosition = tr.endpos;
		m_active = true;
	}
	else
	{
		m_active = false;
	}
}