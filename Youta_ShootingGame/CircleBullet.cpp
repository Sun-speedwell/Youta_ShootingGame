#include "DxLib.h"
#include "CircleBullet.h"
#include "common.h"

#define _USE_MATH_DEFINES
#include <math.h>

CircleBullet::CircleBullet(T_location location, float speed, int degAngle)
	: BulletsBase(location, 5.f, 1, T_location{ 0,0 }, T_location{ 0,0 })
{
	int deg = degAngle % 360;
	double rad = (M_PI / 180) * deg;
	float x = (abs(deg) == 90 || abs(deg) == 270 ? 0 : cos(rad));
	float y = sin(rad);
	this->speed = T_location{ (speed * x),(speed * y) };
}

void CircleBullet::Updata()
{
	T_location newlocation = GetLocation();
	newlocation.y += speed.y;
	newlocation.x += speed.x;
	SetLocation(newlocation);

}
void CircleBullet::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 255, 0));
}

bool CircleBullet::isScreenOut()
{
	//ret ƒŠƒ^[ƒ“—p‚Ì•Ï”
	//GetRadius()‚ğ‘«‚·‚±‚Æ‚Å‰~‚Ì‰‚É”»’è‚ğ‚¸‚ç‚·
	bool ret = ((GetLocation().y + GetRadius()) <= 0);
	if (ret)
	{
		return ret;
	}
	ret = (SCREEN_HEIGHT <= (GetLocation().y - GetRadius()));
	if (ret)
	{
		return ret;
	}

	ret = ((GetLocation().x + GetRadius()) <= 0);
	if (ret)
	{
		return ret;
	}
	ret = (SCREEN_WIDTH <= (GetLocation().x - GetRadius()));
	return ret;
}