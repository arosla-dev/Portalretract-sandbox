#ifndef FUNC_SAVEDELETER_VOLUME_H
#define FUNC_SAVEDELETER_VOLUME_H
#ifdef _WIN32
#pragma once
#endif

#include "baseentity.h"

class CFuncPaintSaveDeletorVolume : public CBaseEntity
{
public:
	DECLARE_CLASS( CFuncPaintSaveDeletorVolume, CBaseEntity );
	DECLARE_DATADESC();

	void Spawn();
	void InputClearSaveTraces( inputdata_t &inputdata );
};

#endif // FUNC_SAVEDELETER_VOLUME_H