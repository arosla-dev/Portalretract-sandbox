#include "cbase.h"
#include "point_paint_detector.h"
#include "portal_util_shared.h"
#include "paint_saverestore.h"

BEGIN_DATADESC( CPointPaintDetector )

	DEFINE_THINKFUNC( DetectThink ),
	DEFINE_THINKFUNC( ApplyPaintThink ),

	DEFINE_INPUTFUNC( FIELD_VOID, "Enable", InputEnable ),
	DEFINE_INPUTFUNC( FIELD_VOID, "Disable", InputDisable ),

	//DEFINE_FIELD( m_bSaveAndReload, FIELD_BOOLEAN ),

END_DATADESC()

IMPLEMENT_SERVERCLASS_ST( CPointPaintDetector, DT_PointPaintDetector )
END_SEND_TABLE()

LINK_ENTITY_TO_CLASS( point_paint_detector, CPointPaintDetector );

CPointPaintDetector::CPointPaintDetector()
{
	//m_bSaveAndReload = false;
}

void CPointPaintDetector::Activate( void )
{
	BaseClass::Activate();
	
	SetThink( &CPointPaintDetector::ApplyPaintThink );
	SetNextThink( gpGlobals->curtime );
}

void CPointPaintDetector::ApplyPaint( void )
{	
	if ( gpGlobals->eLoadType != MapLoad_LoadGame )
	{
		trace_t tr;	
		Vector forward;
		GetVectors( &forward, NULL, NULL );

		UTIL_TraceLine( GetLocalOrigin(), GetLocalOrigin() + ( forward * 128 ), CONTENTS_SOLID, NULL, &tr );
		UTIL_PaintBrushEntity( tr.m_pEnt, tr.endpos, BOUNCE_POWER, 512, 255, tr.plane.normal );
		//m_bSaveAndReload = true;
	}
}

void CPointPaintDetector::ApplyPaintThink()
{
	ApplyPaint();
	
	SetThink( &CPointPaintDetector::DetectThink );
	SetNextThink( gpGlobals->curtime );
}

void CPointPaintDetector::DetectThink( void )
{
	//Msg("DetectThink\n");
	trace_t tr;	
	Vector forward;
	GetVectors( &forward, NULL, NULL );

	UTIL_TraceLine( GetLocalOrigin(), GetLocalOrigin() + ( forward * 128 ), CONTENTS_SOLID, NULL, &tr );

	PaintPowerType power = UTIL_Paint_TracePower( tr.m_pEnt, tr.endpos, tr.plane.normal, NULL );
	if ( power != BOUNCE_POWER )
	{
		//Msg("NOT BOUNCE POWER\n");
#if 0
		if ( m_bSaveAndReload )
		{
			//Msg("SAVING\n");
			//engine->ClientCommand( UTIL_GetLocalPlayer()->edict(), "save paintsave" );
			//SetThink( &CPointPaintDetector::LoadSaveThink );
			//SetNextThink( gpGlobals->curtime + 3.0 );
			return;
		}
		else
#endif
		{
			CBasePlayer *pPlayer = UTIL_GetListenServerHost();
			if ( pPlayer )
			{
				engine->ClientCommand( pPlayer->edict(), "paint_warning" );
			}
			Msg("RestorePaint\n");
			RestorePaint();
		}
	}

	SetNextThink( gpGlobals->curtime );
}

void CPointPaintDetector::InputEnable( inputdata_t &inputdata )
{
	//SetThink( &CPointPaintDetector::DetectThink );
	//SetNextThink( gpGlobals->curtime );
}

void CPointPaintDetector::InputDisable( inputdata_t &inputdata )
{
	//SetThink( NULL );
}