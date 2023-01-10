#pragma once
#include "SphereCollider.h"
#include "BulletsBase.h"
class CharaBase : public SphereCollider
{
private:
    

protected:
    T_location speed;
    //bullets(�|�C���^�z��)
    BulletsBase** bullets;
    int* image;

public:
    CharaBase(T_location location, float radius, T_location speed, T_location angle);

public:
     virtual void Updeta() = 0;
     virtual void Draw() = 0;
     virtual void Hit(int damage) = 0;
     BulletsBase** GetBullets();
     void DeletBullet(int bulletNum);

};

