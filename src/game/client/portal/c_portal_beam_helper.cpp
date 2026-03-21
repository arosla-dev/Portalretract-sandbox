#include "cbase.h"
#include "c_prop_portal.h"
#include "c_portal_beam_helper.h"
#include "vgui_controls/TreeView.h"
#include "beam_shared.h"
#include "coordsize.h"

extern void BeamHelper_Laser_OnTrace( CBaseEntity *pEntity );
C_PortalBeamHelper::C_PortalBeamHelper( void )
{
  m_pBeamTemplate = NULL;
  m_beams.Purge();
}

C_PortalBeamHelper::~C_PortalBeamHelper( void )
{
	for ( int i = 0 ; i < m_beams.Count(); ++i )
	{
		m_beams[i]->Remove();
		m_beams[i] = NULL;
	}
}

void C_PortalBeamHelper::Init( C_Beam *pBeamTemplate )
{
	m_pBeamTemplate = pBeamTemplate;
	m_beams.AddToTail( pBeamTemplate );
}

C_Beam *C_PortalBeamHelper::CreateBeam( void )
{
	C_Beam *pNewBeam = C_Beam::BeamCreate( m_pBeamTemplate->GetModelName(), m_pBeamTemplate->GetWidth() );

	pNewBeam->SetType( m_pBeamTemplate->GetType() );
	pNewBeam->SetBeamFlags( m_pBeamTemplate->GetBeamFlags() );  
	pNewBeam->SetHaloScale( m_pBeamTemplate->GetHaloScale() );
	pNewBeam->SetWidth( m_pBeamTemplate->GetWidth() );
	pNewBeam->SetEndWidth( m_pBeamTemplate->GetEndWidth() );
	pNewBeam->SetFadeLength( m_pBeamTemplate->GetFadeLength() );
	pNewBeam->SetNoise( m_pBeamTemplate->GetNoise() );
	pNewBeam->SetRenderColorR( m_pBeamTemplate->GetRenderColor().r );
	pNewBeam->SetRenderColorG( m_pBeamTemplate->GetRenderColor().g );
	pNewBeam->SetRenderColorB( m_pBeamTemplate->GetRenderColor().b );
	pNewBeam->SetRenderAlpha( m_pBeamTemplate->GetRenderAlpha() );
	pNewBeam->SetFrame( m_pBeamTemplate->GetFrame() );
	pNewBeam->SetScrollRate( m_pBeamTemplate->GetScrollRate() );
  
	pNewBeam->SetHDRColorScale( m_pBeamTemplate->GetHDRColorScale() );

  return pNewBeam;
}

void C_PortalBeamHelper::UpdatePointDirection( C_BaseEntity *pEmitter, Vector &vStartPoint, Vector &vDirection, unsigned int fMask, ITraceFilter *pTraceFilter, trace_t *tr )
{
	Vector vEndPoint = vStartPoint + ( vDirection * MAX_TRACE_LENGTH );

	C_PortalBeamHelper::UpdatePoints( pEmitter, vStartPoint, vEndPoint, fMask, pTraceFilter, tr );
}

void C_PortalBeamHelper::UpdatePoints( C_BaseEntity *pEmitter, Vector &vStartPoint, Vector &vEndPoint, unsigned int fMask, ITraceFilter *pTraceFilter, trace_t *tr )
{
	Vector vStart = vStartPoint;

	Vector vDir = vEndPoint - vStartPoint;
	VectorNormalize( vDir );

	bool bHitPortal = true;

	trace_t tempTrace;

	int i;
	for ( i = 0; bHitPortal && i < 10; ++i )
	{
		if ( i == m_beams.Count() )
		{
			m_beams.AddToTail( CreateBeam() );
		}

		if ( i )
		{
			m_beams[i]->SetEndWidth( m_pBeamTemplate->GetEndWidth() );
		}

		Ray_t ray;
		ray.Init( vStart, (vDir * MAX_TRACE_LENGTH) + vStart );
    
		UTIL_ClearTrace( tempTrace );
		enginetrace->TraceRay( ray, fMask, pTraceFilter, &tempTrace );
		
		BeamHelper_Laser_OnTrace( pEmitter );
		
		m_beams[i]->PointsInit( vStart, tempTrace.endpos );
		m_beams[i]->SetAbsOrigin( vStart );
		m_beams[i]->TurnOff();
		
		C_Prop_Portal *pPortal;
		if ( UTIL_DidTraceTouchPortals( ray, tempTrace, &pPortal, NULL )
		  && pPortal
		  && pPortal->IsActivedAndLinked() )
		{
			Ray_t rayTransformed;
			UTIL_Portal_RayTransform( pPortal->m_matrixThisToLinked, ray, rayTransformed );

			vDir = rayTransformed.m_Delta;
			VectorNormalize( vDir );
			UTIL_Portal_PointTransform( pPortal->m_matrixThisToLinked, tempTrace.endpos, vStart );

			// RETRACT: HACK! This fixes the problem of lasers going through entities!
			vStart += (vDir * DIST_EPSILON);

			bHitPortal = true;
		}
		else
		{
			bHitPortal = false;
		}
	}

	int iLastBeam = m_beams.Count() - 1;
	int nNumRemoved = m_beams.Count() - i;

	bool bRemovedAll = m_beams.Count() == i;

	if ( nNumRemoved >= 0 && !bRemovedAll && iLastBeam >= 0 )
	{
#ifdef DEBUG
		int iCycleCount = 0;
#endif
		do
		{
#ifdef DEBUG
			++iCycleCount;
#endif
			AssertMsg( iCycleCount < 100, "You're probably stuck in a loop if you managed to get this high" );
			--nNumRemoved;
			--iLastBeam;
			GetLastBeam()->Remove();
			m_beams.FindAndRemove( GetLastBeam() );
		} while ( nNumRemoved > 0 && iLastBeam >= 0 );
	}

	if ( tr )
	{
		*tr = tempTrace;
	}
}

void C_PortalBeamHelper::TurnOff( void )
{
	for ( int i = 0; i < m_beams.Count(); ++i )
	{
		//Msg("Turn off Beam %i\n", i);
		m_beams[i]->TurnOn();
	}
}

void C_PortalBeamHelper::TurnOn( void )
{
	for ( int i = 0; i < m_beams.Count(); ++i )
	{
		//Msg("Turn on Beam %i\n", i);
		m_beams[i]->TurnOff();
		m_beams[i]->UpdateVisibility();
		//m_beams[i]->OnDisableShadowDepthRenderingChanged();
		//m_beams[i]->OnShadowDepthRenderingCacheableStateChanged();
	}
}

int C_PortalBeamHelper::BeamCount( void )
{
	return m_beams.Count();
}

C_Beam *C_PortalBeamHelper::GetBeam( int i )
{
	return m_beams[i];
}

C_Beam *C_PortalBeamHelper::GetFirstBeam( void )
{
	return m_beams[0];
}

C_Beam *C_PortalBeamHelper::GetLastBeam( void )
{
	return m_beams[m_beams.Count() - 1];
}