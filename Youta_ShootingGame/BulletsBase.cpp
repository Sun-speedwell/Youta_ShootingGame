#include "BulletsBase.h"

BulletsBase::BulletsBase(T_location location, float radius, int damage, T_location speed, T_location angle)
	:SphereCollider(location,radius),damage(damage), speed(speed),angle(angle)
{

}
int BulletsBase::GetDamage()
{
	return damage;
}
void BulletsBase::SetSpeed(int getx, int gety)
{
	speed.x = getx;
	speed.y = gety;
}

void BulletsBase::SetAngle(int getx, int gety)
{
	angle.x = getx;
	angle.y = gety;
}