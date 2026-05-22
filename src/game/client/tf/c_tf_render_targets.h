#ifndef _INCLUDED_TF_RENDER_TARGETS_H
#define _INCLUDED_TF_RENDER_TARGETS_H
#ifdef _WIN32
#pragma once
#endif

#include "baseclientrendertargets.h" // Base class, with interfaces called by engine and inherited members to init common render targets

#ifndef INFESTED_DLL 
#pragma message ( "This file should only be built with AS:Infested builds" )
#endif

// externs
class IMaterialSystem;
class IMaterialSystemHardwareConfig;

class CTFRenderTargets : public CBaseClientRenderTargets
{
	// no networked vars
	DECLARE_CLASS_GAMEROOT( CTFRenderTargets, CBaseClientRenderTargets );
public:
	virtual void InitClientRenderTargets( IMaterialSystem* pMaterialSystem, IMaterialSystemHardwareConfig* pHardwareConfig );
	virtual void ShutdownClientRenderTargets();

	ITexture* InitTFMotionBlurTexture( IMaterialSystem* pMaterialSystem );
	ITexture* GetTFMotionBlurTexture( void );

private:
	CTextureReference m_TFMotionBlurTexture;	
};

extern CTFRenderTargets* g_pTFRenderTargets;


#endif //_INCLUDED_TF_RENDER_TARGETS_H