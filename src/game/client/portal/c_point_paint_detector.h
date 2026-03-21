#ifndef C_POINT_PAINT_DETECTOR_H
#define C_POINT_PAINT_DETECTOR_H
#ifdef _WIN32
#pragma once
#endif

#include "c_baseentity.h"

class C_PointPaintDetector : public C_BaseEntity
{
public:
	DECLARE_CLASS( C_PointPaintDetector, C_BaseEntity );
	DECLARE_CLIENTCLASS();
	
	void Spawn();

	virtual void OnDataChanged( DataUpdateType_t updateType );
	virtual void ClientThink();
};

#endif // POINT_PAINT_DETECTOR_H