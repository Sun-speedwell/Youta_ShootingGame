#include "CharaBase.h"

CharaBase::CharaBase(T_location location, float radius, T_location speed, T_location angle)
	: SphereCollider(location, radius),speed(speed), image(nullptr), bullets(nullptr)
{
	
}

BulletsBase** CharaBase::GetBullets()
{
	return bullets;
}

void CharaBase::DeletBullet(int bulletNum)
{
	delete bullets[bulletNum];
	bullets[bulletNum] = nullptr;

	for (int i = bulletNum + 1; i < 30; i++) {
		if (bullets[i] == nullptr) {
			break;
		}
		bullets[i - 1] = bullets[i];
		bullets[i] = nullptr;
	}

}
