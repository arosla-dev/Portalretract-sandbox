#ifndef PROP_BOX_H
#define PROP_BOX_H

#include "props.h"
#include "player_pickup_paint_power_user.h"

enum WeightedCubeType_e
{
	CUBE_STANDARD,
	CUBE_COMPANION,
	CUBE_REFLECTIVE,
	CUBE_SPHERE,
};

class CPropWeightedCube : public PlayerPickupPaintPowerUser< CPhysicsProp >
{
public:
	DECLARE_CLASS( CPropWeightedCube, PlayerPickupPaintPowerUser< CPhysicsProp > );
	DECLARE_DATADESC();
	//DECLARE_SERVERCLASS();

	CPropWeightedCube();

	void Spawn( void );
	void Precache( void );
	
	virtual	bool	ShouldCollide( int collisionGroup, int contentsMask ) const OVERRIDE;

	virtual bool	HasPreferredCarryAnglesForPlayer( CBasePlayer *pPlayer );
	virtual QAngle	PreferredCarryAngles( void );
	
#ifndef CLIENT_DLL
	#define CREATE_CUBE_AT_POSITION false
	static void CreatePortalWeightedCube( WeightedCubeType_e objectType, bool bAtCursorPosition = true, const Vector &position = vec3_origin );
#endif

	// instead of getting which model it uses, we can just ask this
	WeightedCubeType_e GetCubeType( void ) { return m_nCubeType; }
	
	void SetLaser( CBaseEntity *pLaser );
	CBaseEntity* GetLaser()
	{
		return m_hLaser.Get();
	}
	bool HasLaser( void )
	{
		return m_hLaser.Get() != NULL;
	}

	COutputEvent m_OnFizzled;

private:
	
	void SetCubeType( void );

	void InputDissolve( inputdata_t &inputdata );

	WeightedCubeType_e m_nCubeType;
	EHANDLE					m_hLaser;
};

bool UTIL_IsReflectiveCube( CBaseEntity *pEntity );
bool UTIL_IsWeightedCube( CBaseEntity *pEntity );

#endif // PROP_BOX_H