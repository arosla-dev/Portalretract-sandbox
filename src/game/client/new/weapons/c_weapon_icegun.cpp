//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//===========================================================================//

#include "cbase.h"
#include "hud.h"
#include "in_buttons.h"
#include "beamdraw.h"
#include "c_weapon__stubs.h"
#include "basehlcombatweapon_shared.h"
//#include "clienteffectprecachesystem.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

PRECACHE_REGISTER_BEGIN(GLOBAL, PrecacheEffectIceGun)
PRECACHE(MATERIAL, "sprites/physbeam")
PRECACHE_REGISTER_END()

class C_BeamQuadratic : public CDefaultClientRenderable
{
public:
	C_BeamQuadratic();
	void			Update(C_BaseEntity* pOwner);

	// IClientRenderable
	virtual const Vector& GetRenderOrigin(void) { return m_worldPosition; }
	virtual const QAngle& GetRenderAngles(void) { return vec3_angle; }
	virtual bool					ShouldDraw(void) { return true; }
	virtual bool					IsTransparent(void) { return true; }
	virtual bool					ShouldReceiveProjectedTextures(int flags) { return false; }
	virtual int						DrawModel(int flags, const RenderableInstance_t& instance);

	// Returns the bounds relative to the origin (render bounds)
	virtual void	GetRenderBounds(Vector& mins, Vector& maxs)
	{
		// bogus.  But it should draw if you can see the end point
		mins.Init(-32, -32, -32);
		maxs.Init(32, 32, 32);
	}

	const matrix3x4_t& RenderableToWorldTransform()
	{
		static matrix3x4_t mat;
		SetIdentityMatrix( mat );
		PositionMatrix(GetRenderOrigin(), mat);
		//AngleMatrix(GetRenderAngles(), GetRenderOrigin(), mat); maybe this is better?
		return mat;
	}

	C_BaseEntity* m_pOwner;
	Vector					m_targetPosition;
	Vector					m_worldPosition;
	int						m_active;
	int						m_viewModelIndex;
};

C_BeamQuadratic::C_BeamQuadratic()
{
	m_pOwner = NULL;
}

void C_BeamQuadratic::Update(C_BaseEntity* pOwner)
{
	m_pOwner = pOwner;
	if (m_active)
	{
		if (m_hRenderHandle == INVALID_CLIENT_RENDER_HANDLE)
		{
			ClientLeafSystem()->AddRenderable(this, true, RENDERABLE_IS_TRANSLUCENT, RENDERABLE_MODEL_ENTITY);
		}
		else
		{
			ClientLeafSystem()->RenderableChanged(m_hRenderHandle);
		}
	}
	else if (!m_active && m_hRenderHandle != INVALID_CLIENT_RENDER_HANDLE)
	{
		ClientLeafSystem()->RemoveRenderable(m_hRenderHandle);
	}
}


int	C_BeamQuadratic::DrawModel(int flags, const RenderableInstance_t& instance)
{
	Vector points[3];
	QAngle tmpAngle;

	if (!m_active)
		return 0;

	C_BaseEntity* pEnt = cl_entitylist->GetEnt(m_viewModelIndex);
	if (!pEnt)
		return 0;

	CMatRenderContextPtr pRenderContext(materials);

	pEnt->GetAttachment(1, points[0], tmpAngle);

	points[1] = 0.5 * (m_targetPosition + points[0]);

	// a little noise 11t & 13t should be somewhat non-periodic looking
	//points[1].z += 4*sin( gpGlobals->curtime*11 ) + 5*cos( gpGlobals->curtime*13 );
	points[2] = m_worldPosition;

	IMaterial* pMat = materials->FindMaterial("sprites/physbeam", TEXTURE_GROUP_CLIENT_EFFECTS);
	Vector color(1, 1, 1);

	float scrollOffset = gpGlobals->curtime - (int)gpGlobals->curtime;
	pRenderContext->Bind(pMat);
	DrawBeamQuadratic(points[0], points[1], points[2], 13, color, scrollOffset);
	return 1;
}


class C_WeaponIcegun : public C_BaseHLCombatWeapon
{
	DECLARE_CLASS(C_WeaponIcegun, C_BaseHLCombatWeapon);
public:
	C_WeaponIcegun() {}

	DECLARE_CLIENTCLASS();
	DECLARE_PREDICTABLE();

	void OnDataChanged(DataUpdateType_t updateType)
	{
	BaseClass::OnDataChanged(updateType);
	m_beam.Update(this);
	}

private:
	C_WeaponIcegun(const C_WeaponIcegun&);

	C_BeamQuadratic	m_beam;
};

STUB_WEAPON_CLASS_IMPLEMENT(weapon_icegun, C_WeaponIcegun);

IMPLEMENT_CLIENTCLASS_DT(C_WeaponIcegun, DT_WeaponIcegun, CWeaponIcegun)
RecvPropVector(RECVINFO_NAME(m_beam.m_targetPosition, m_targetPosition)),
RecvPropVector(RECVINFO_NAME(m_beam.m_worldPosition, m_worldPosition)),
RecvPropInt(RECVINFO_NAME(m_beam.m_active, m_active)),
RecvPropInt(RECVINFO_NAME(m_beam.m_viewModelIndex, m_viewModelIndex)),
END_RECV_TABLE()