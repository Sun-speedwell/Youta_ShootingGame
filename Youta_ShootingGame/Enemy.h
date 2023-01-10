#pragma once
#include "CharaBase.h"
class Enemy : public CharaBase
{
private:
	int hp;
	int point;
	int BulletInterval;
	int shotNum;

public:
	Enemy(T_location location);

public:
	virtual void Updeta() override;
	virtual void Draw() override;
	virtual void Hit(int damage) override;
	bool HpCheck();
	int GetPoint();
	void Move();

};

