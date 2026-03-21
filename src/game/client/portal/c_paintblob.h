//========= Copyright © Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
//==========================================================================//
#ifndef C_PAINTBLOB_H
#define C_PAINTBLOB_H

#define MAX_BLOB_RENDERABLES 32

#include "paint_blobs_shared.h"

class C_PaintBlobRenderable;

class C_PaintBlob : public CBasePaintBlob
{
public:
	C_PaintBlob();
	~C_PaintBlob();

	virtual void PaintBlobPaint( const trace_t &tr );

	virtual void Init( const Vector &vecOrigin, const Vector &vecVelocity, int paintType, float flMaxStreakTime, float flStreakSpeedDampenRate, CBaseEntity* pOwner, bool bSilent, bool bDrawOnly );
};

#endif // C_PAINTBLOB_H
