#include "ItemBase.h"

ItemBase::ItemBase(T_location location, float radius, E_ITEM_TYPE type, T_location speed)
	:SphereCollider(location, radius), type(type), speed(speed)
{

}

E_ITEM_TYPE ItemBase::GetType()
{
	return type;
}