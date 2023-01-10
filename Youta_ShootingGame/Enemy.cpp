#include "DxLib.h"
#include "Enemy.h"
#include "StraightBullets.h"
#include "CircleBullet.h"
#include "TestBullets.h"

//状態管理
struct MoveInformation
{
	T_location targetLocation;
	int pattern;
	int next;
	int waitTimeFlame;
	int attackPattern;
};

MoveInformation moveInfo[10] = {
	{   640,150,0,1,  0,0},
	{1200.4,150,0,2,  0,0},
	{     0,  0,1,3,180,1},
	{  80.2,150,0,4,  0,2},
	{     0,  0,1,5,180,1},
	{1200.4,150,0,2,  0,1},
};

//指定座標
T_location locations[3] = {
	{   640,150},
	{1200.4,150},
	{  80.2,150},
};

//指定座標の設定
int next[3] = {
	1,
	2,
	1
};

int current = 0;

//メンバ変数の初期化を初期化子リストで初期化
Enemy::Enemy(T_location location)
	: CharaBase(location, 20.f, T_location{ 1,2 }, T_location{0,0}), hp(10), point(10), shotNum(0)
{
	//enemys = new CharaBase * [30];//同時に存在出来る弾の数
	//for (int i = 0; i < 30; i++)
	//{
	//	bullets[i] = nullptr;
	//}
	bullets = new BulletsBase * [30];//同時に存在出来る弾の数
	for (int i = 0; i < 30; i++)
	{
		bullets[i] = nullptr;
	}

}

void Enemy::Updeta()
{
	/*T_location newLocation = GetLocation();
	newLocation.y += speed.y;
	SetLocation(newLocation);*/

	/*int EnemyCount;
	for (EnemyCount = 0; EnemyCount < 30; EnemyCount++) {
		if ([EnemyCount] == nullptr) {
			break;
		}

	}*/
	Move();

	int bulletCount;
	for (bulletCount = 0; bulletCount < 30; bulletCount++)//弾があるかどうか
	{
		if (bullets[bulletCount] == nullptr)//弾がない
		{
			break;
		}
		bullets[bulletCount]->Updata();

		//画面外に行ったら弾を消す
		if (bullets[bulletCount]->isScreenOut())
		{

			DeletBullet(bulletCount);
			bulletCount--;

		}


	}

	if (BulletInterval++>=30)
	{
		if (bulletCount < 30 && bullets[bulletCount] == nullptr)
		{
			bullets[bulletCount] = new CircleBullet(GetLocation(), 2.f,(10 * shotNum));//new StraightBullets(GetLocation());
			shotNum++;
		}
		BulletInterval = 0;
	}

}

void Enemy::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 255));
	for (int bulletCount = 0; bulletCount < 30; bulletCount++)//弾があるかどうか
	{
		if (bullets[bulletCount] == nullptr)//弾がない
		{
			break;
		}
		bullets[bulletCount]->Draw();
	}
}

void Enemy::Hit(int damage)
{
	if (0 < damage)
	{
		hp -= damage;
		if (hp < 0)//hpをマイナスにしない
		{
			hp = 0;
		}
	}
}

bool Enemy::HpCheck()
{
	bool ret = (hp <= 0);
	return ret;
}

int Enemy::GetPoint()
{
	return point;
}

void Enemy::Move()
{
	T_location nextLocation = GetLocation();//現在座標を取得

	//指定座標と現在座標と同じか
	if ((nextLocation.y == locations[current].y) &&
		(nextLocation.x == locations[current].x))
	{
		//次の指定座標の設定
		current = next[current];
	}
	else
	{//指定座標と同じでない

		//y座標が同じでない
		if (nextLocation.y != locations[current].y)
		{
			//指定座標が大きい場合
			if (nextLocation.y < locations[current].y)
			{
				nextLocation.y += speed.y;
				//指定座標を越えた場合
				if ((GetLocation().y <= locations[current].y) &&
					(locations[current].y <= nextLocation.y))
				{
					//指定座標に上書き
					nextLocation.y = locations[current].y;
				}
			}
			else
			{//指定座標が小さい場合
				nextLocation.y -= speed.y;
				//指定座標を越えた場合
				if ((nextLocation.y <= locations[current].y) &&
					(locations[current].y <= GetLocation().y))
				{
					//指定座標に上書き
					nextLocation.y = locations[current].y;
				}
			}
		}

		//x座標が同じでない
		if (nextLocation.x != locations[current].x)
		{
			//指定座標が大きい場合
			if (nextLocation.x < locations[current].x)
			{
				nextLocation.x += speed.x;
				//指定座標を越えた場合
				if ((GetLocation().x <= locations[current].x) &&
					(locations[current].x <= nextLocation.x))
				{
					//指定座標に上書き
					nextLocation.x = locations[current].x;
				}
			}
			else
			{//指定座標が小さい場合
				nextLocation.x -= speed.x;
				//指定座標を越えた場合
				if ((nextLocation.x <= locations[current].x) &&
					(locations[current].x <= GetLocation().x))
				{
					//指定座標に上書き
					nextLocation.x = locations[current].x;
				}
			}
		}
	}
	//座標の更新
	SetLocation(nextLocation);
}