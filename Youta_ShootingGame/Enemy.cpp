#include "DxLib.h"
#include "Enemy.h"
#include "StraightBullets.h"
#include "CircleBullet.h"
#include "TestBullets.h"

//��ԊǗ�
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

//�w����W
T_location locations[3] = {
	{   640,150},
	{1200.4,150},
	{  80.2,150},
};

//�w����W�̐ݒ�
int next[3] = {
	1,
	2,
	1
};

int current = 0;

//�����o�ϐ��̏��������������q���X�g�ŏ�����
Enemy::Enemy(T_location location)
	: CharaBase(location, 20.f, T_location{ 1,2 }, T_location{0,0}), hp(10), point(10), shotNum(0)
{
	//enemys = new CharaBase * [30];//�����ɑ��ݏo����e�̐�
	//for (int i = 0; i < 30; i++)
	//{
	//	bullets[i] = nullptr;
	//}
	bullets = new BulletsBase * [30];//�����ɑ��ݏo����e�̐�
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
	for (bulletCount = 0; bulletCount < 30; bulletCount++)//�e�����邩�ǂ���
	{
		if (bullets[bulletCount] == nullptr)//�e���Ȃ�
		{
			break;
		}
		bullets[bulletCount]->Updata();

		//��ʊO�ɍs������e������
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
	for (int bulletCount = 0; bulletCount < 30; bulletCount++)//�e�����邩�ǂ���
	{
		if (bullets[bulletCount] == nullptr)//�e���Ȃ�
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
		if (hp < 0)//hp���}�C�i�X�ɂ��Ȃ�
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
	T_location nextLocation = GetLocation();//���ݍ��W���擾

	//�w����W�ƌ��ݍ��W�Ɠ�����
	if ((nextLocation.y == locations[current].y) &&
		(nextLocation.x == locations[current].x))
	{
		//���̎w����W�̐ݒ�
		current = next[current];
	}
	else
	{//�w����W�Ɠ����łȂ�

		//y���W�������łȂ�
		if (nextLocation.y != locations[current].y)
		{
			//�w����W���傫���ꍇ
			if (nextLocation.y < locations[current].y)
			{
				nextLocation.y += speed.y;
				//�w����W���z�����ꍇ
				if ((GetLocation().y <= locations[current].y) &&
					(locations[current].y <= nextLocation.y))
				{
					//�w����W�ɏ㏑��
					nextLocation.y = locations[current].y;
				}
			}
			else
			{//�w����W���������ꍇ
				nextLocation.y -= speed.y;
				//�w����W���z�����ꍇ
				if ((nextLocation.y <= locations[current].y) &&
					(locations[current].y <= GetLocation().y))
				{
					//�w����W�ɏ㏑��
					nextLocation.y = locations[current].y;
				}
			}
		}

		//x���W�������łȂ�
		if (nextLocation.x != locations[current].x)
		{
			//�w����W���傫���ꍇ
			if (nextLocation.x < locations[current].x)
			{
				nextLocation.x += speed.x;
				//�w����W���z�����ꍇ
				if ((GetLocation().x <= locations[current].x) &&
					(locations[current].x <= nextLocation.x))
				{
					//�w����W�ɏ㏑��
					nextLocation.x = locations[current].x;
				}
			}
			else
			{//�w����W���������ꍇ
				nextLocation.x -= speed.x;
				//�w����W���z�����ꍇ
				if ((nextLocation.x <= locations[current].x) &&
					(locations[current].x <= GetLocation().x))
				{
					//�w����W�ɏ㏑��
					nextLocation.x = locations[current].x;
				}
			}
		}
	}
	//���W�̍X�V
	SetLocation(nextLocation);
}