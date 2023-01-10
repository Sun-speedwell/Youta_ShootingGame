#pragma once
#include "BulletsBase.h"
class TestBullets : public BulletsBase
{
public:
	TestBullets(T_location location);
public:
	virtual void Updata() override;
	virtual void Draw() override;
	virtual bool isScreenOut() override;
};

