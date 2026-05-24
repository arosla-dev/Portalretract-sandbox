//TOOLGUN LOL AYY LMAO

#include "cbase.h"
#include "in_buttons.h"
#include "basegrenade_shared.h"
#include "KeyValues.h"
#include "filesystem.h"
//#include "entities/emitter.h"

#ifdef CLIENT_DLL
#include "particles/particles.h"
#include "c_basehlcombatweapon.h"
#else
#include "particle_system.h"
#include "basehlcombatweapon.h"
#endif

#ifndef CLIENT_DLL
#include "props.h"
#include "gamestats.h"
#include "beam_shared.h"
#include "ammodef.h"
#include "baseanimating.h"
#include "EntityFlame.h"
#include "explode.h"
#include "entitylist.h"
#include "player.h"
#include "vphysics/constraints.h"
#include "rope.h"
#include "basegrenade_shared.h"
#endif

#include "tier0/memdbgon.h"

#ifndef CLIENT_DLL
ConVar toolmode("toolmode", "0");
ConVar red("red", "0");
ConVar green("green", "0");
ConVar blue("blue", "0");
ConVar duration("duration", "0");
ConVar exp_magnitude("exp_magnitude", "0");
ConVar exp_radius("exp_radius", "0");
ConVar tool_create("tool_create", "");

ConVar multitool_decal("multitool_decal", "0");
ConVar multitool_explosion_magnitude("multitool_explosion_magnitude", "100");
ConVar multitool_explosion_radius("multitool_explosion_radius", "150");
#endif

#define BEAM_SPRITE "sprites/bluelaser1.vmt"

#ifdef CLIENT_DLL
#define CWeaponToolGun C_WeaponToolGun
#endif

extern CBaseEntity *FindPickerEntity( CBasePlayer *pPlayer );

class CWeaponToolGun : public CBaseHLCombatWeapon
{
private:
	DECLARE_CLASS(CWeaponToolGun, CBaseHLCombatWeapon);;
	DECLARE_DATADESC();
	
#ifndef CLIENT_DLL
	DECLARE_ACTTABLE();
#endif

public:
	DECLARE_NETWORKCLASS();
	DECLARE_PREDICTABLE();

	CWeaponToolGun();
	virtual ~CWeaponToolGun();

private:	
	virtual void PrimaryAttack();
#ifndef CLIENT_DLL
	virtual void SecondaryAttack();
#endif
	virtual void Precache();
	virtual bool HasAnyAmmo() { return true; }
	virtual bool HasPrimaryAmmo() { return true; }
	virtual bool HasSecondaryAmmo() { return true; }
	virtual void ItemPostFrame();
	virtual void InitKeyValues();
#ifndef CLIENT_DLL
	virtual void DrawBeam( const Vector &startPos, const Vector &endPos, float width );
	virtual void DoImpactEffect( trace_t &tr, int nDamageType );
#endif

	IPhysicsConstraint* m_pConstraint;

private:

	bool m_bWeldFirstClick;
	CBaseEntity* m_pFirstWeldEntity;
	CBaseEntity* m_pSecondWeldEntity;
	CBaseEntity* m_constWeldEntity;

	CBaseEntity* m_pent1;
	CBaseEntity* m_pent2;
	Vector m_vFirstWeldPos;
	void WeldObjects(CBaseEntity* pEntity1, CBaseEntity* pEntity2);

#ifndef CLIENT_DLL
	CHandle<CEntityFlame> m_pIgniter;
	CRopeKeyframe* pRope;
#endif	
	CNetworkVar( int, m_iMode );
};


#ifndef CLIENT_DLL
acttable_t CWeaponToolGun::m_acttable[] = 
{
	{ ACT_MP_STAND_IDLE,				ACT_MP_STAND_PRIMARY,					false },
	{ ACT_MP_RUN,						ACT_MP_RUN_PRIMARY,						false },
	{ ACT_MP_CROUCH_IDLE,				ACT_MP_CROUCH_PRIMARY,					false },
	{ ACT_MP_CROUCHWALK,				ACT_MP_CROUCHWALK_PRIMARY,				false },
	{ ACT_MP_JUMP_START,				ACT_MP_JUMP_START_PRIMARY,				false },
	{ ACT_MP_JUMP_FLOAT,				ACT_MP_JUMP_FLOAT_PRIMARY,				false },
	{ ACT_MP_JUMP_LAND,					ACT_MP_JUMP_LAND_PRIMARY,				false },
	{ ACT_MP_AIRWALK,					ACT_MP_AIRWALK_PRIMARY,					false },
};

IMPLEMENT_ACTTABLE( CWeaponToolGun );
#endif


IMPLEMENT_NETWORKCLASS_ALIASED( WeaponToolGun, DT_WeaponToolGun )

BEGIN_NETWORK_TABLE( CWeaponToolGun, DT_WeaponToolGun )
#ifdef CLIENT_DLL
	RecvPropInt( RECVINFO(m_iMode) ),
#else
	SendPropInt( SENDINFO(m_iMode), 10, SPROP_UNSIGNED ),
#endif
END_NETWORK_TABLE()

#ifdef CLIENT_DLL
BEGIN_PREDICTION_DATA( CWeaponToolGun )
END_PREDICTION_DATA()
#endif

LINK_ENTITY_TO_CLASS( weapon_toolgun, CWeaponToolGun );
PRECACHE_WEAPON_REGISTER( weapon_toolgun );

BEGIN_DATADESC(CWeaponToolGun)
	DEFINE_FIELD(m_iMode, FIELD_INTEGER),
END_DATADESC()

CWeaponToolGun::CWeaponToolGun() : BaseClass()
{
#ifndef CLIENT_DLL
	m_pIgniter = NULL;
#endif
	InitKeyValues();
}

CWeaponToolGun::~CWeaponToolGun()
{
}

void CWeaponToolGun::InitKeyValues()
{
}

void CWeaponToolGun::Precache()
{
	BaseClass::Precache();
}

void CWeaponToolGun::PrimaryAttack()
{
#ifndef CLIENT_DLL
	m_flNextPrimaryAttack = gpGlobals->curtime + 0.5f;

	CBasePlayer* pOwner = ToBasePlayer(GetOwner());

	QAngle vecAngles(0, GetAbsAngles().y - 90, 0);

	Vector vForward, vRight, vUp;
	pOwner->EyeVectors(&vForward, &vRight, &vUp);
	Vector muzzlePoint = pOwner->Weapon_ShootPosition() + vForward + vRight + vUp;
	Vector vecAiming = pOwner->GetAutoaimVector(AUTOAIM_5DEGREES);

	trace_t tr;
	UTIL_TraceLine(muzzlePoint, muzzlePoint + vForward * MAX_TRACE_LENGTH, MASK_SHOT, this, COLLISION_GROUP_NONE, &tr);
	if (tr.fraction == 1.0)
		return;
	Vector vecShootOrigin, vecShootDir;
	vecShootOrigin = pOwner->Weapon_ShootPosition();
	DrawBeam(vecShootOrigin, tr.endpos, 4);

	/* 0 - remover
	   1 - setcolor
	   2 - modelscale
	   3 - igniter
	   4 - dynamite
	   5 - spawner
	   6 - emitter
	*/
	m_iMode = toolmode.GetInt();

	switch (m_iMode)
	{
	case 0:
	{
		if (tr.m_pEnt->IsNPC() || tr.m_pEnt->VPhysicsGetObject())
		{
			UTIL_Remove(tr.m_pEnt);
		}
	}
	break;

	case 1:
		if (tr.m_pEnt->IsNPC() || tr.m_pEnt->VPhysicsGetObject())
		{
			int r = red.GetInt();
			int g = green.GetInt();
			int b = blue.GetInt();
			tr.m_pEnt->SetRenderColor(r, g, b);
			tr.m_pEnt->SetRenderAlpha(255);
		}
		break;

	case 2:
		if (tr.m_pEnt->IsNPC() || tr.m_pEnt->VPhysicsGetObject())
		{
			float a = duration.GetFloat();
			dynamic_cast<CBaseAnimating*>(tr.m_pEnt)->SetModelScale(a, 0.0f);
		}
		break;

	case 3:
		if (tr.m_pEnt->IsNPC() || tr.m_pEnt->VPhysicsGetObject())
		{
			UTIL_Remove(m_pIgniter);
			m_pIgniter = CEntityFlame::Create(tr.m_pEnt, true);
		}
		break;
	case 4:
	{
		CBaseEntity* pEntity = CreateEntityByName(tool_create.GetString());
		if (pEntity)
		{
			pEntity->SetAbsOrigin(tr.endpos);
			pEntity->SetAbsAngles(vecAngles);
			DispatchSpawn(pEntity);
			pEntity->Activate();
		}
	}
	break;
	case 5:
	{
		switch (multitool_decal.GetInt())
		{
		case 0:
			UTIL_DecalTrace(&tr, "RedGlowFade");
			break;
		case 1:
			UTIL_DecalTrace(&tr, "Scorch");
			break;
		case 2:
			UTIL_DecalTrace(&tr, "Antion.Unburrow");
			break;
		case 3:
			UTIL_DecalTrace(&tr, "Blood");
			break;
		case 4:
			UTIL_DecalTrace(&tr, "YellowBlood");
			break;
		case 5:
			UTIL_DecalTrace(&tr, "BeerSplash");
			break;
		case 6:
			UTIL_DecalTrace(&tr, "SmallScorch");
			break;
		case 7:
			UTIL_DecalTrace(&tr, "Impact.Concrete");
			break;

		default:
			Msg("Decal not found!\n");
			Msg("bruh...\n");
			break;
		}
	}

	case 6:
	{
		ExplosionCreate(tr.endpos, GetAbsAngles(), pOwner, multitool_explosion_magnitude.GetInt(), multitool_explosion_radius.GetInt(), true);
	}
	break;

	case 7: /* Rope Tool */
	{
		CBaseEntity* pEnt = tr.m_pEnt;

		if (!m_bWeldFirstClick)
		{
			if (pEnt->VPhysicsGetObject())
				m_pFirstWeldEntity = CreateEntityByName("prop_dynamic");
			else
				m_pFirstWeldEntity = CreateEntityByName("env_sprite");
			if (m_pFirstWeldEntity)
			{
				Msg("First rope!\n");
				m_pFirstWeldEntity->SetName(MAKE_STRING("ropetoolbase"));
				m_pFirstWeldEntity->SetAbsOrigin(tr.endpos);
				m_pFirstWeldEntity->SetAbsAngles(vecAngles);
				if (pEnt->VPhysicsGetObject())
				{

					PrecacheModel("models/weapons/w_bugbait.mdl");
					m_pFirstWeldEntity->SetModel("models/weapons/w_bugbait.mdl");
					m_pFirstWeldEntity->SetRenderColor(0, 0, 0);
					m_pFirstWeldEntity->SetRenderAlpha(0);
					m_pFirstWeldEntity->SetMoveType(MOVETYPE_NOCLIP);
					m_pFirstWeldEntity->GetCollideable();
				}
				if (pEnt)
					m_pFirstWeldEntity->SetParent(pEnt);
				DispatchSpawn(m_pFirstWeldEntity);
				m_pFirstWeldEntity->Activate();
				if (pEnt->VPhysicsGetObject())
				{
					constraint_fixedparams_t fixed;
					fixed.Defaults();
					fixed.InitWithCurrentObjectState(m_pFirstWeldEntity->GetParent()->VPhysicsGetObject(), pEnt->VPhysicsGetObject());

					m_pConstraint = physenv->CreateFixedConstraint(m_pFirstWeldEntity->GetParent()->VPhysicsGetObject(), pEnt->VPhysicsGetObject(), NULL, fixed);
					m_pConstraint->SetGameData((void*)this);
				}

			}

			if (!m_pFirstWeldEntity)
			{
				Warning("Rope Tool: Failed to create first weld entity\n");
				m_bWeldFirstClick = false;
				return;
			}

			if (pEnt)
				m_pent1 = pEnt;

			m_bWeldFirstClick = true;

		}
		else
		{
			if (pEnt->VPhysicsGetObject())
				m_pSecondWeldEntity = CreateEntityByName("prop_dynamic");
			else
				m_pSecondWeldEntity = CreateEntityByName("env_sprite");
			if (m_pSecondWeldEntity)
			{
				Msg("second rope!\n");
				m_pSecondWeldEntity->SetName(MAKE_STRING("ropetoolbase2"));
				m_pSecondWeldEntity->SetAbsOrigin(tr.endpos);
				m_pSecondWeldEntity->SetAbsAngles(vecAngles);
				if (pEnt->VPhysicsGetObject())
				{

					PrecacheModel("models/weapons/w_bugbait.mdl");
					m_pSecondWeldEntity->SetModel("models/weapons/w_bugbait.mdl");
					m_pSecondWeldEntity->SetMoveType(MOVETYPE_NOCLIP);
					m_pSecondWeldEntity->GetCollideable();
				}
				if (pEnt)
					m_pSecondWeldEntity->SetParent(pEnt);
				DispatchSpawn(m_pSecondWeldEntity);
				m_pSecondWeldEntity->Activate();
				if (pEnt->VPhysicsGetObject())
				{
					constraint_fixedparams_t secondfixed;
					secondfixed.Defaults();
					secondfixed.InitWithCurrentObjectState(m_pSecondWeldEntity->GetParent()->VPhysicsGetObject(), pEnt->VPhysicsGetObject());

					m_pConstraint = physenv->CreateFixedConstraint(m_pSecondWeldEntity->GetParent()->VPhysicsGetObject(), pEnt->VPhysicsGetObject(), NULL, secondfixed);
					m_pConstraint->SetGameData((void*)this);
				}
			}


			if (!m_pSecondWeldEntity)
			{
				Warning("Rope Tool: Failed to create second weld entity\n");
				m_bWeldFirstClick = false;
				return;
			}

			if (pEnt)
				m_pent2 = pEnt;

			pRope = new CRopeKeyframe();
			pRope->Create(m_pFirstWeldEntity, m_pSecondWeldEntity, NULL, NULL, 2, "cable/rope.vmt", 5 );
			pRope->EnableCollision();
			
			pRope->KeyValue("RopeShader", "1");

			// check if we have a physics object

			
				constraint_lengthparams_t constriant;
				constriant.Defaults();
				constriant.InitWorldspace(m_pent1->VPhysicsGetObject(), m_pent2->VPhysicsGetObject(), tr.startpos, tr.endpos, true);

				physenv->CreateLengthConstraint(m_pent1->VPhysicsGetObject(), m_pent2->VPhysicsGetObject(), nullptr, constriant);
				physenv->CreateLengthConstraint(m_pFirstWeldEntity->GetParent()->VPhysicsGetObject(), m_pSecondWeldEntity->GetParent()->VPhysicsGetObject(), nullptr, constriant);
			

			m_bWeldFirstClick = false;
		}
		break;
	}

	}
#endif
}

#ifndef CLIENT_DLL
void CWeaponToolGun::SecondaryAttack()
{
	m_flNextSecondaryAttack = gpGlobals->curtime + 1.0;

	CBasePlayer *pOwner = ToBasePlayer(GetOwner());

	Vector vForward, vRight, vUp;
	pOwner->EyeVectors(&vForward, &vRight, &vUp);
	Vector muzzlePoint = pOwner->Weapon_ShootPosition() + vForward + vRight + vUp;

	trace_t tr;
	UTIL_TraceLine(muzzlePoint, muzzlePoint + vForward * MAX_TRACE_LENGTH, MASK_SHOT, this, COLLISION_GROUP_NONE, &tr);

	Vector vecShootOrigin, vecShootDir;
	vecShootOrigin = pOwner->Weapon_ShootPosition();
	DrawBeam( vecShootOrigin, tr.endpos, 4 );

	m_iMode = toolmode.GetInt();

	switch(m_iMode)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		{
//			CStickyBomb::DetonateByOperator( GetOwner() );
		}
	case 6:
		{
			//MakeEffectEmitter( tr.endpos, tr.endpos, 10 );
		}
	}
}
#endif

void CWeaponToolGun::ItemPostFrame()
{
	BaseClass::ItemPostFrame();
}

#ifndef CLIENT_DLL
void CWeaponToolGun::DrawBeam( const Vector &startPos, const Vector &endPos, float width )
{
	UTIL_Tracer( startPos, endPos, 0, TRACER_DONT_USE_ATTACHMENT, 6500, false, "GaussTracer" );
	CBeam *pBeam = CBeam::BeamCreate( BEAM_SPRITE, 4 );
	pBeam->SetStartPos( startPos );
	pBeam->PointEntInit( endPos, this );
	pBeam->SetEndAttachment( LookupAttachment("Muzzle") );
	pBeam->SetWidth( width );
	pBeam->SetBrightness( 255 );
	pBeam->SetColor( 66, 170, 255 );
	pBeam->RelinkBeam();
	pBeam->LiveForTime( 0.1f );
}

void CWeaponToolGun::DoImpactEffect( trace_t &tr, int nDamageType )
{
	DrawBeam( tr.startpos, tr.endpos, 4 );
}

#endif
