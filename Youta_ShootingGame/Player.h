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
	void Hit(int damage) override;
	void Hit(class ItemBase* item);
	bool LifeCheck();
	int GetScore();
	void AddScore(int score);
};

