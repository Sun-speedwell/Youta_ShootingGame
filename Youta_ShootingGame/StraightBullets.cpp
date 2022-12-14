#include "DxLib.h"
#include "StraightBullets.h"
#include "common.h"

StraightBullets::StraightBullets(T_location location)
	: BulletsBase(location, 5.f, 1, T_location{ 0,2 }, T_location{ 0,0 })
{

}

void StraightBullets::Updata()
{
	T_location newlocation = GetLocation();
	newlocation.y -= speed.y;
	SetLocation(newlocation);

}
void StraightBullets::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 255, 0));
}

bool StraightBullets::isScreenOut()
{
	//ret リターン用の変数
	//GetRadius()を足すことで円の縁に判定をずらす
	bool ret = ((GetLocation().y + GetRadius()) <= 0);
	if (ret)
	{
		return ret;
	}
	ret = (SCREEN_HEIGHT<=(GetLocation().y - GetRadius()));
	return ret;
}