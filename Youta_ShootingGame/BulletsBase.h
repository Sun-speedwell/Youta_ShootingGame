#pragma once
#include "SphereCollider.h"
class BulletsBase : public SphereCollider
{
private:
	int damage;

protected:
	T_location speed;
	T_location angle;

public:
	BulletsBase(T_location location, float radius, int damage, T_location speed, T_location angle);

public:
	virtual void Updata() = 0;
	virtual void Draw() = 0;
	int GetDamage();
	virtual bool isScreenOut() = 0;
	void SetSpeed(int getx, int gety);
	void SetAngle(int getx, int gety);
};

