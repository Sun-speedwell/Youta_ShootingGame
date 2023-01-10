#include "DxLib.h"
#include "Player.h"
#include "StraightBullets.h"
#include "KeyManager.h"
#include "Recovery.h"

Player::Player(T_location location)
	: CharaBase(location, 10.f, T_location{ 2,2 }, T_location{ 0,0 }), score(0), life(10)
{
	bullets = new BulletsBase * [30];//�����ɑ��ݏo����e�̐�
	for (int i = 0; i < 30; i++)
	{
		bullets[i] = nullptr;
	}
}

void Player::Updeta() 
{
	T_location newLocation = GetLocation();

	if (KeyManager::OnKeyPressed(KEY_INPUT_W))
	{
		newLocation.y -= speed.y;
	}
	if (KeyManager::OnKeyPressed(KEY_INPUT_S))
	{
		newLocation.y += speed.y;
	}
	if (KeyManager::OnKeyPressed(KEY_INPUT_A))
	{
		newLocation.x -= speed.x;
	}
	if (KeyManager::OnKeyPressed(KEY_INPUT_D))
	{
		newLocation.x += speed.x;
	}
	//newLocation.x += 1;
	SetLocation(newLocation);

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

			/*delete bullets[bulletCount];
			bullets[bulletCount] = nullptr;*/

			//�z���O�ɋl�߂�

			//���쏈��
			/*for (int i = 0; i < 30; i++) {
				if (i >= 29) {
					bullets[i] = nullptr;
					break;
				}
				if (bullets[i] == nullptr) {
					if (bullets[i + 1] != nullptr) {
						bullets[i] = bullets[i + 1];
						bullets[i + 1] = nullptr;
					}
				}
			}*/

			//+�p�^�[��
			/*for (int i = bulletCount; i < (30 - 1); i++) {
				if (bullets[i + 1] == nullptr) {
					break;
				}
				bullets[i] = bullets[i + 1];
				bullets[i + 1] = nullptr;
			}*/

			//-�p�^�[��
			/*for (int i = bulletCount + 1; i < 30; i++) {
				if (bullets[i] == nullptr) {
					break;
				}
				bullets[i - 1] = bullets[i];
				bullets[i] = nullptr;
			}

			bulletCount--;*/



		}


	}

	if (KeyManager::OnMousePressed(MOUSE_INPUT_LEFT) /*CheckHitKey(KEY_INPUT_SPACEMOUSE_INPUT_LEFT)*/)
	{
		if (bulletCount < 30 && bullets[bulletCount] == nullptr)
		{
			bullets[bulletCount] = new StraightBullets(GetLocation());
		}
	}
}

void Player::Draw() 
{
#define _DEBUG_MODE_

#ifdef _DEBUG_MODE_
	DrawFormatString(10, 10, GetColor(255, 255, 255), "life=%d", life);
#endif


	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 0));
	for (int bulletCount = 0; bulletCount < 30; bulletCount++)//�e�����邩�ǂ���
	{
		if (bullets[bulletCount] == nullptr)//�e���Ȃ�
		{
			break;
		}
		bullets[bulletCount]->Draw();
	}
}

void Player::Hit(int damage) 
{
	if (0 <= damage)
	{
		life -= damage;
		if (life < 0)
		{
			life = 0;
		}
	}
}

void Player::Hit(ItemBase* item)
{
	//switch�̒��ŕϐ������Ɣg�������̒��܂ŕϐ��������Ă邱�ƂɂȂ�
	switch (item->GetType())
	{
	case E_ITEM_TYPE::Heal:
	{
		Recovery* recovery = dynamic_cast<Recovery*>(item);
		life += recovery->GetVolume();
		break;
	}

	default:
		break;
	}
}

bool Player::LifeCheck() 
{
	bool ret = (life <= 0);
	return ret;
}

int Player::GetScore() 
{
	return score;
}

void Player::AddScore(int score)
{
	if (0 <= score) {
		this->score += score;
	}
}
