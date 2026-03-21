#include "cbase.h"
#include "func_savedeleter_volume.h"
#include "paint_saverestore.h"

BEGIN_DATADESC( CFuncPaintSaveDeletorVolume )

DEFINE_INPUTFUNC( FIELD_VOID, "ClearSaveTraces", InputClearSaveTraces )

END_DATADESC()

LINK_ENTITY_TO_CLASS( func_paint_savedeletor_volume, CFuncPaintSaveDeletorVolume )

void CFuncPaintSaveDeletorVolume::Spawn( void )
{	
	SetModel( STRING( GetModelName() ) );
	BaseClass::Spawn();
}

void CFuncPaintSaveDeletorVolume::InputClearSaveTraces( inputdata_t &inputdata )
{
	ClearPaintTracesInVolume( this );
}