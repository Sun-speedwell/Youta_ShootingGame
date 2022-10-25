#pragma once
#include "BulletsBase.h"
class StraightBullets : public BulletsBase
{
public:
	StraightBullets(T_location location);
public:
	virtual void Updata() override;
	virtual void Draw() override;
};

