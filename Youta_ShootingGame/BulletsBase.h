#pragma once
#include "SphereCollider.h"
class BulletsBase : public SphereCollider
{
private:
	int damage;

protected:
	T_location speed;

public:
	BulletsBase(T_location location, float radius, int damage, T_location speed);

public:
	virtual void Updata() = 0;
	virtual void Draw() = 0;
	int GetDamage();
};

