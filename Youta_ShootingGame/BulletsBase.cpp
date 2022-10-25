#include "BulletsBase.h"

BulletsBase::BulletsBase(T_location location, float radius, int damage, T_location speed)
	:SphereCollider(location,radius),damage(damage), speed(speed)
{

}
int BulletsBase::GetDamage()
{
	return damage;
}