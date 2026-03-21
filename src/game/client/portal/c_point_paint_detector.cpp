#include "cbase.h"
#include "c_point_paint_detector.h"
#include "ienginevgui.h"
#include "basepanel.h"

IMPLEMENT_CLIENTCLASS_DT( C_PointPaintDetector, DT_PointPaintDetector, CPointPaintDetector )
END_RECV_TABLE()

void C_PointPaintDetector::Spawn()
{
	BaseClass::Spawn();
}

void C_PointPaintDetector::OnDataChanged( DataUpdateType_t updateType )
{
	BaseClass::OnDataChanged( updateType );
	
	if ( updateType == DATA_UPDATE_CREATED )
	{
		//Assert( !"TODO: save/load a game instead of restoring directly to prevent a crash!" );
		SetNextClientThink( gpGlobals->curtime + ( gpGlobals->interval_per_tick * 2 ) );
	}
}

void C_PointPaintDetector::ClientThink( void )
{
	trace_t tr;	
	Vector forward;
	GetVectors( &forward, NULL, NULL );

	UTIL_TraceLine( GetLocalOrigin(), GetLocalOrigin() + ( forward * 128 ), CONTENTS_SOLID, NULL, &tr );

	if ( tr.DidHitNonWorldEntity() )
	{
		Assert( false );
		return;
	}

	PaintPowerType power = UTIL_Paint_TracePower( tr.m_pEnt, tr.endpos, tr.plane.normal, NULL );
	if ( power == NO_POWER )
	{
		engine->ClientCmd_Unrestricted( "restore_paint" );
		enginevgui->ActivateGameUI();
		BasePanel()->OnOpenPaintWarningDialog();
#ifdef DEBUG
		if ( gpGlobals->maxClients != 1 )
		{
			AssertMsg( false, "Find a way to restore paint on the client side" );
		}
#endif
		//RestorePaint();
		//Msg("client: restoring paint\n");
	}

	SetNextClientThink( gpGlobals->curtime );
}

CON_COMMAND( paint_warning, "" )
{
	enginevgui->ActivateGameUI();
	BasePanel()->OnOpenPaintWarningDialog();
}