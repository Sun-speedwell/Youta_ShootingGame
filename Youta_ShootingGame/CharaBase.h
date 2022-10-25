#pragma once
#include "SphereCollider.h"
#include "BulletsBase.h"
class CharaBase : public SphereCollider
{
private:
    T_location speed;

protected:
    //bullets(ポインタ配列)
    BulletsBase** bullets;
    int* image;

public:
    CharaBase(T_location location, float radius, T_location speed);

public:
     virtual void Updeta() = 0;
     virtual void Draw() = 0;
     virtual void Hit() = 0;
     BulletsBase** GetBullets();

};

