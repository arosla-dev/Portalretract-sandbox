//========= Copyright © Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
//==========================================================================//
#ifndef PAINT_SAVERESTORE_H
#define PAINT_SAVERESTORE_H

class ISaveRestoreBlockHandler;

ISaveRestoreBlockHandler *GetPaintSaveRestoreBlockHandler();

void RestorePaint();
void ClearPaintTraces();
void ClearPaintTracesInVolume( CBaseEntity *pVolume );

#endif // PAINT_SAVERESTORE_H