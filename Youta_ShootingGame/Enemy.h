#pragma once
#include "CharaBase.h"
class Enemy : public CharaBase
{
private:
	int hp;
	int point;

public:
	virtual void Updeta() override;
	virtual void Draw() override;
	virtual void Hit() override;
	bool HpCheck();
	int GetPoint();

};

