//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
//==========================================================================//
#include "cbase.h"
#include "model_types.h"

#include "c_paintblob.h"
#include "c_prop_paint_bomb.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

C_PaintBlob::C_PaintBlob()
{
}


C_PaintBlob::~C_PaintBlob()
{

}


void C_PaintBlob::PaintBlobPaint( const trace_t &tr )
{
	if ( m_bDrawOnly )
		return;

	Vector vecTouchPos = tr.endpos;
	Vector vecNormal = tr.plane.normal;

	PlayEffect( vecTouchPos, vecNormal );
	
}

void C_PaintBlob::Init( const Vector &vecOrigin, const Vector &vecVelocity, int paintType, float flMaxStreakTime, float flStreakSpeedDampenRate, CBaseEntity* pOwner, bool bSilent, bool bDrawOnly )
{
	CBasePaintBlob::Init( vecOrigin, vecVelocity, paintType, flMaxStreakTime, flStreakSpeedDampenRate, pOwner, bSilent, bDrawOnly );
}