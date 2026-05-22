#include "cbase.h"
#include "c_tf_render_targets.h"
#include "materialsystem\imaterialsystem.h"
#include "materialsystem/ITexture.h"

ITexture* CTFRenderTargets::InitTFMotionBlurTexture( IMaterialSystem* pMaterialSystem )
{
#ifdef _X360
	// @TODO: need to figure out where in EDRAM to put motion blur texture
	return NULL;
#else // !_X360
	return pMaterialSystem->CreateNamedRenderTargetTextureEx(
		"_rt_ASWMotionBlur",
		256, 256, RT_SIZE_FULL_FRAME_BUFFER,
		pMaterialSystem->GetBackBufferFormat(),
		MATERIAL_RT_DEPTH_NONE, 
		TEXTUREFLAGS_CLAMPS | TEXTUREFLAGS_CLAMPT,
		0 );
#endif // _X360
}

ITexture* CTFRenderTargets::GetTFMotionBlurTexture()
{
	// @TODO: need to figure out where in EDRAM to put motion blur texture 
	Assert( !IsX360() );
	if(!m_TFMotionBlurTexture)
	{
		m_TFMotionBlurTexture.InitRenderTarget(256, 256, RT_SIZE_FULL_FRAME_BUFFER, IMAGE_FORMAT_ARGB8888, MATERIAL_RT_DEPTH_NONE, false);
		Assert(!IsErrorTexture(m_TFMotionBlurTexture));
	}
 
	return m_TFMotionBlurTexture;
} 

//-----------------------------------------------------------------------------
// Purpose: InitClientRenderTargets, interface called by the engine at material system init in the engine
// Input  : pMaterialSystem - the interface to the material system from the engine (our singleton hasn't been set up yet)
//			pHardwareConfig - the user's hardware config, useful for conditional render targets setup
//-----------------------------------------------------------------------------
void CTFRenderTargets::InitClientRenderTargets( IMaterialSystem* pMaterialSystem, IMaterialSystemHardwareConfig* pHardwareConfig )
{	
	m_TFMotionBlurTexture.Init( InitTFMotionBlurTexture( pMaterialSystem ) );

	// Water effects & camera from the base class (standard HL2 targets)
	BaseClass::InitClientRenderTargets( pMaterialSystem, pHardwareConfig );
}

//-----------------------------------------------------------------------------
// Purpose: Shutdown client render targets. This gets called during shutdown in the engine
// Input  :  - 
//-----------------------------------------------------------------------------
void CTFRenderTargets::ShutdownClientRenderTargets()
{
	m_TFMotionBlurTexture.Shutdown();	

	// Clean up standard HL2 RTs (camera and water)
	BaseClass::ShutdownClientRenderTargets();
}


static CTFRenderTargets g_TFRenderTargets;
EXPOSE_SINGLE_INTERFACE_GLOBALVAR( CTFRenderTargets, IClientRenderTargets, CLIENTRENDERTARGETS_INTERFACE_VERSION, g_TFRenderTargets );
CTFRenderTargets* g_pTFRenderTargets = &g_TFRenderTargets;