#pragma once
#include "BulletsBase.h"
class CircleBullet : public BulletsBase
{
public:
	CircleBullet(T_location location, float speed, int degAngle);

public:
	virtual void Updata() override;
	virtual void Draw() override;
	virtual bool isScreenOut() override;
};

