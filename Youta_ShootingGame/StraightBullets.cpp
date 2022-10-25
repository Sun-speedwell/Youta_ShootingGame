#include "DxLib.h"
#include "StraightBullets.h"

StraightBullets::StraightBullets(T_location location)
	: BulletsBase(location, 5.f, 1, T_location{ 0,2 })
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