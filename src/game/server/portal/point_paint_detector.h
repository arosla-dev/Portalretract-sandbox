#ifndef POINT_PAINT_DETECTOR_H
#define POINT_PAINT_DETECTOR_H
#ifdef _WIN32
#pragma once
#endif

#include "baseentity.h"

class CPointPaintDetector : public CBaseEntity
{
public:
	DECLARE_CLASS( CPointPaintDetector, CBaseEntity );
	DECLARE_DATADESC();
	DECLARE_SERVERCLASS();

	int UpdateTransmitState() OVERRIDE
	{
		return SetTransmitState( FL_EDICT_ALWAYS );
	}

	CPointPaintDetector();

	void Activate();
	void ApplyPaint();
	
	void DetectThink();
	void ApplyPaintThink();

	void InputEnable( inputdata_t &inputdata );
	void InputDisable( inputdata_t &inputdata );

	//bool m_bSaveAndReload;
};

#endif // POINT_PAINT_DETECTOR_H