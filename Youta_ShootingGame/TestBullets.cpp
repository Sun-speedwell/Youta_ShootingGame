#include "TestBullets.h"
#include "DxLib.h"
#include "common.h"
#include <math.h>

#define PI 3.1415926f

TestBullets::TestBullets(T_location location)
	: BulletsBase(location, 5.f, 1, T_location{ 2,2 }, T_location{ 0.1,0.1 })
{

}

void TestBullets::Updata()
{
	static float FAngle = 0.1;
	T_location newlocation = GetLocation();
	angle.x += FAngle;
	angle.y -= FAngle;
	newlocation.x -= speed.x * cos(angle.x);
	newlocation.y -= speed.y * sin(angle.y);
	//FAngle += 0.01;
	speed.x += 0.01;
	speed.y += 0.01;
	SetLocation(newlocation);

}
void TestBullets::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 255, 0));
}

bool TestBullets::isScreenOut()
{
	//ret ƒŠƒ^[ƒ“—p‚Ì•Ï”
	//GetRadius()‚ğ‘«‚·‚±‚Æ‚Å‰~‚Ì‰‚É”»’è‚ğ‚¸‚ç‚·
	bool ret = ((GetLocation().y + GetRadius()) <= 0);
	if (ret)
	{
		return ret;
	}
	ret = (SCREEN_HEIGHT <= (GetLocation().y - GetRadius()));
	return ret;
}