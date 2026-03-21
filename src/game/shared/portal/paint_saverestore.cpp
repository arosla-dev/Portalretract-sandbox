//========= Copyright © Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
//==========================================================================//
#include "cbase.h"
#include "isaverestore.h"
#include "paint_stream_manager.h"

#ifdef GAME_DLL

#include "projectedwallentity.h"
#include "paint_database.h"
#include "world.h"
#else

#include "c_world.h"

#endif

#include "saverestore_utlvector.h"
#include "collisionutils.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"
#define NO_PROJECTED_WALL
class CPaintTrace
{
public:
	DECLARE_SIMPLE_DATADESC();

	EHANDLE m_hPaintedEntity;
	PaintPowerType m_Power;
	Vector m_vContactPoint;
	float m_flPaintRadius;
	float m_flAlphaPercent;
};

BEGIN_SIMPLE_DATADESC( CPaintTrace )
	
	DEFINE_FIELD( m_hPaintedEntity, FIELD_EHANDLE ),
	DEFINE_FIELD( m_Power, FIELD_INTEGER ),
	DEFINE_FIELD( m_vContactPoint, FIELD_VECTOR ),
	DEFINE_FIELD( m_flPaintRadius, FIELD_FLOAT ),
	DEFINE_FIELD( m_flAlphaPercent, FIELD_FLOAT ),

END_DATADESC()

class CPaintSaveDataHolder
{
public:

	DECLARE_DATADESC();

	void OnRestore();

	CUtlVector<CPaintTrace> m_PaintTraces;
};

static CPaintSaveDataHolder g_PaintSaveDataHolder;

BEGIN_DATADESC_NO_BASE( CPaintSaveDataHolder )

	DEFINE_UTLVECTOR( m_PaintTraces, FIELD_EMBEDDED ),

END_DATADESC()

void CPaintSaveDataHolder::OnRestore()
{
#ifdef GAME_DLL
	if ( m_PaintTraces.Count() == 0 )
		return;
	for ( int i = 0; i < m_PaintTraces.Count(); ++i )
	{
		CPaintTrace *pTrace = &m_PaintTraces[i];
		CBaseEntity *pBrushEntity = pTrace->m_hPaintedEntity;
		// It's possible for a brush entity to be deleted
		if ( !pBrushEntity )
		{
			pBrushEntity = GetWorldEntity();
		}
		Color color = MapPowerToColor( pTrace->m_Power );
		engine->PaintSurface( pBrushEntity->GetModel(), pTrace->m_vContactPoint, color, pTrace->m_flPaintRadius );
	}
#endif
}
#ifdef GAME_DLL
CON_COMMAND( restore_paint, "" )
{
	if ( !UTIL_IsCommandIssuedByServerAdmin() )
		return;

	g_PaintSaveDataHolder.OnRestore();
}
#endif

bool AreaHasOtherPaintPower( CBaseEntity* pBrushEntity, const Vector& contactPoint, PaintPowerType power, Vector vContactNormal )
{
	float radius = 1;
	const int alphaThreshold = 100;

	Color traceColor = UTIL_Paint_TraceColor( pBrushEntity, contactPoint, contactPoint, &radius );
	Color powerColor = MapPowerToColor( power );
	
	// Check the colors, and if they're different then save
	if ( (
		powerColor.r() != traceColor.r() ||
		powerColor.g() != traceColor.g() ||
		powerColor.b() != traceColor.b()
		) && 
		powerColor.a() != 0 )
	{
	}
	else
	{
		if ( powerColor.a() == 0 ) // Special exception for NO_POWER
		{
			if ( traceColor.a() == 0 )
			{
				return false;
			}
		}
		else
		{
			// Check if the alpha is substantial enough
			if ( alphaThreshold < traceColor.a() )
			{
				return false;
			}
		}
	}
	
	//Msg( "traceColor: %i %i %i %i\n", (int)traceColor.r(), (int)traceColor.g(), (int)traceColor.b(), (int)traceColor.a() );
	//Msg( "powerColor: %i %i %i %i\n", (int)powerColor.r(), (int)powerColor.g(), (int)powerColor.b(), (int)powerColor.a() );

	return true;
}

void AddPaintDataToSave( CBaseEntity* pBrushEntity, const Vector& contactPoint, PaintPowerType power, float flPaintRadius, float flAlphaPercent, Vector vContactNormal )
{
	CPaintTrace trace;
	trace.m_hPaintedEntity = pBrushEntity;
	trace.m_vContactPoint = contactPoint;
	trace.m_Power = power;
	trace.m_flPaintRadius = flPaintRadius;
	trace.m_flAlphaPercent = flAlphaPercent;
	
	g_PaintSaveDataHolder.m_PaintTraces.AddToTail( trace );
}

void RestorePaint()
{
	g_PaintSaveDataHolder.OnRestore();
}

void ClearPaintTraces()
{
	g_PaintSaveDataHolder.m_PaintTraces.Purge();
}

void ClearPaintTracesInVolume( CBaseEntity *pVolume )
{
	Vector mins;
	Vector maxs;
	pVolume->CollisionProp()->WorldSpaceAABB( &mins, &maxs );
	//Msg( "mins %f %f %f\n", mins.x, mins.y, mins.z );
	//Msg( "maxs %f %f %f\n", maxs.x, maxs.y, maxs.z );
	//NDebugOverlay::Box( pVolume->GetLocalOrigin(), mins, maxs, 255, 0, 0, 128, 4 );
#if 1
	for ( int i = 0; i < g_PaintSaveDataHolder.m_PaintTraces.Count(); ++i )
	{
		CPaintTrace *pTrace = &g_PaintSaveDataHolder.m_PaintTraces[i];
		
		if ( IsPointInBox( pTrace->m_vContactPoint, mins, maxs ) )
		{
			g_PaintSaveDataHolder.m_PaintTraces.FastRemove(i);
			i = 0;		
		}
	}
#endif
}

class CPaintSaveRestoreBlockHandler : public CDefSaveRestoreBlockHandler
{
	virtual const char *GetBlockName() { return "PaintDatabase"; };

	virtual void PreSave( CSaveRestoreData * ) {}

	virtual void Save( ISave *pSave )
	{
		if ( !HASPAINTMAP )
		{
			return;
		}
		
		pSave->WriteAll( &g_PaintSaveDataHolder, g_PaintSaveDataHolder.GetDataDescMap() );

#ifdef GAME_DLL
		// save paintmap data
		// Retract: No point in saving it if it's not being restored now
		//PaintDatabase.SavePaintmapData( pSave );
#endif // GAME_DLL
	}

	virtual void WriteSaveHeaders( ISave * ) {}

	virtual void PostSave() {}

	virtual void PreRestore()
	{
		if ( !HASPAINTMAP )
		{
			return;
		}

#ifdef GAME_DLL
		PaintDatabase.RemoveAllPaint();
#endif
	}

	virtual void ReadRestoreHeaders( IRestore * ) {}
	
	virtual void Restore( IRestore *pRestore, bool fCreatePlayers )
	{
		if ( !HASPAINTMAP )
		{
			return;
		}
		
		pRestore->ReadAll( &g_PaintSaveDataHolder, g_PaintSaveDataHolder.GetDataDescMap() );

#ifdef GAME_DLL
		// restore paintmap data
		// Retract: Even though there's nothing, this can cause the game to freeze, disabling
		//PaintDatabase.RestorePaintmapData( pRestore );
#endif // GAME_DLL
	}

	virtual void PostRestore()
	{

	}
};

CPaintSaveRestoreBlockHandler g_PaintSaveRestoreBlockHandler;

ISaveRestoreBlockHandler *GetPaintSaveRestoreBlockHandler()
{
	return &g_PaintSaveRestoreBlockHandler;
}
