#pragma once
#include "CharaBase.h"
class Player : public CharaBase
{
private:
	int score;
	int life;
public:
	Player(T_location location);

public:
	void Updeta() override;
	void Draw() override;
	void Hit() override;
	bool LifeCheck();
	int GetScore();
};

