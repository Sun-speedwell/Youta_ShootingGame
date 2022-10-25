#include "DxLib.h"
#include "Player.h"
#include "StraightBullets.h"
#include "KeyManager.h"

Player::Player(T_location location)
	: CharaBase(location, 10.f, T_location{ 2,2 }), score(0), life(10)
{
	bullets = new BulletsBase * [30];//“¯‚É‘¶İo—ˆ‚é’e‚Ì”
	for (int i = 0; i < 30; i++)
	{
		bullets[i] = nullptr;
	}
}

void Player::Updeta() 
{
	T_location newLocation = GetLocation();
	newLocation.x += 1;
	SetLocation(newLocation);

	int bulletCount;
	for (bulletCount = 0; bulletCount < 30; bulletCount++)//’e‚ª‚ ‚é‚©‚Ç‚¤‚©
	{
		if (bullets[bulletCount] == nullptr)//’e‚ª‚È‚¢
		{
			break;
		}
		bullets[bulletCount]->Updata();
	}

	if (KeyManager::OnMouseClicked(MOUSE_INPUT_LEFT) /*CheckHitKey(KEY_INPUT_SPACEMOUSE_INPUT_LEFT)*/)
	{
		if (bulletCount < 30 && bullets[bulletCount] == nullptr)
		{
			bullets[bulletCount] = new StraightBullets(GetLocation());
		}
	}
}

void Player::Draw() 
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 0));
	for (int bulletCount = 0; bulletCount < 30; bulletCount++)//’e‚ª‚ ‚é‚©‚Ç‚¤‚©
	{
		if (bullets[bulletCount] == nullptr)//’e‚ª‚È‚¢
		{
			break;
		}
		bullets[bulletCount]->Draw();
	}
}

void Player::Hit() 
{

}

bool Player::LifeCheck() 
{
	bool ret = (life <= 0);
	return 0;
}

int Player::GetScore() 
{
	return score;
}

