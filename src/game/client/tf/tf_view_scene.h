//========= Copyright © 1996-2005, Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================//

#ifndef TF_VIEW_SCENE_H
#define TF_VIEW_SCENE_H
#ifdef _WIN32
#pragma once
#endif

#include "viewrender.h"

//-----------------------------------------------------------------------------
// Purpose: Implements the interview to view rendering for the client .dll
//-----------------------------------------------------------------------------
class CTFViewRender : public CViewRender
{
public:
	CTFViewRender();

	virtual void OnRenderStart();
	virtual void Render2DEffectsPreHUD( const CViewSetup &view );

	virtual bool	AllowScreenspaceFade( void ) { return false; }

private:
	void DoMotionBlur( const CViewSetup &view );
};

#endif //TF_VIEW_SCENE_H