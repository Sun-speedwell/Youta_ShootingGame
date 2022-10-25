#include "CharaBase.h"

CharaBase::CharaBase(T_location location, float radius, T_location speed)
	: SphereCollider(location, radius),speed(speed), image(nullptr), bullets(nullptr)
{
	
}

BulletsBase** CharaBase::GetBullets()
{
	return bullets;
}