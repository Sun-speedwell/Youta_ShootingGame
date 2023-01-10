#include "GameMainScene.h"
#include "Recovery.h"
GameMainScene::GameMainScene()
{
	T_location Location = T_location{ 20,100 };
	player = new Player(Location);

	enemy = new Enemy * [10];
	for (int i = 0; i < 10; i++) {
		enemy[i] = nullptr;
	}

	enemy[0] = new Enemy(T_location{ 200, 100 });
	enemy[1] = new Enemy(T_location{ 600, 400 });
	enemy[2] = new Enemy(T_location{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });

	item = new ItemBase * [10];
	for (int i = 0; i < 10; i++) {
		item[i] = nullptr;
	}
}

//描画以外の更新を実装する
void GameMainScene::Update() {
	/*T_location Location = T_location{ 100,100 };
	Player test = Player(Location);
	test.Draw();
	if (test.HitSphere(player))
	{
		return;
	}*/
	player->Updeta();

	int enemyCount;
	for (enemyCount = 0; enemyCount < 10; enemyCount++) {
		if (enemy[enemyCount] == nullptr) {
			break;
		}
		enemy[enemyCount]->Updeta();
	}

	for (int i = 0; i < 10; i++)
	{
		if (item[i] == nullptr)
		{
			break;
		}
		item[i]->Update();
	}

	BulletsBase** bullet = player->GetBullets();

	for (enemyCount = 0; enemyCount < 10; enemyCount++) 
	{
		if (enemy[enemyCount] == nullptr) 
		{
			break;
		}

		/*bullet = enemy[enemyCount]->GetBullets();

		for (int i = 0; i < 30; i++) 
		{
			if (bullet[i] == nullptr) 
			{
				break;
			}

			if (player->HitSphere(bullet[i]))
			{
				player->Hit(bullet[i]->GetDamage());

				enemy[enemyCount]->DeletBullet(i);
				i--;
			}
		}*/

		BulletsBase** enemybullet = enemy[enemyCount]->GetBullets();

		for (int EnemybulletCount = 0; EnemybulletCount < 30; EnemybulletCount++)
		{
			if (enemybullet[EnemybulletCount] == nullptr)
			{
				break;
			}

			//EnemybulletCount[enemybullet]->SetSpeed(0, -2);
			if (player->HitSphere(enemybullet[EnemybulletCount]))
			{
				player->Hit(enemybullet[EnemybulletCount]->GetDamage());
				//弾を削除する
				enemy[enemyCount]->DeletBullet(EnemybulletCount);
				EnemybulletCount--;

				if (player->LifeCheck())
				{
					/*delete player;
					player = nullptr;
					break;*/
					player->SetLocation(T_location{ -20,-100 });
				}

			}
		}

		for (int bulletCount = 0; bulletCount < 30; bulletCount++) 
		{
			if (bullet[bulletCount] == nullptr) 
			{
				break;
			}

			if (enemy[enemyCount]->HitSphere(bullet[bulletCount]))
			{
				//エネミーにプレイヤーの弾がヒットしている

				//エネミーにダメージを与える
				enemy[enemyCount]->Hit(bullet[bulletCount]->GetDamage());
				
				//弾を削除する
				player->DeletBullet(bulletCount);
				bulletCount--;
				
				//エネミーのHPが0以下だったら、エネミーを削除する
				if (enemy[enemyCount]->HpCheck())
				{

					for (int i = 0; i < 10; i++)
					{
						if (item[i] == nullptr)
						{
							item[i] = new Recovery(enemy[enemyCount]->GetLocation());
							break;
						}
					}

					//スコアの加算
					player->AddScore(enemy[enemyCount]->GetPoint());

					//エネミーの削除
					delete enemy[enemyCount];
					enemy[enemyCount] = nullptr;

					for (int i = enemyCount + 1; i < 10; i++) {
						if (enemy[i] == nullptr) {
							break;
						}
						enemy[i - 1] = enemy[i];
						enemy[i] = nullptr;
					}
					enemyCount--;
					break;
				}

			}
		}

		//BulletsBase** enemybullet = enemy[enemyCount]->GetBullets();

	}

	for (int itemCount = 0; itemCount < 10; itemCount++)
	{
		if (item[itemCount] == nullptr)
		{
			break;
		}
		if (item[itemCount]->HitSphere(player) == true)
		{

			//回復処理
			player->Hit(item[itemCount]);

			delete item[itemCount];
			item[itemCount] = nullptr;

			//配列を前に詰める
				for (int i = itemCount+1; i < 10; i++)
				{
					if (item[i] == nullptr)
					{
						break;
					}
					item[i - 1] = item[i];
					item[i] = nullptr;
				}
				itemCount--;
		}
	}

}

//描画に関することを実装する
void GameMainScene::Draw() const {
	player->Draw();

	for (int enemyCount = 0; enemyCount < 10; enemyCount++) {
		if (enemy[enemyCount] == nullptr) {
			break;
		}
		enemy[enemyCount]->Draw();
	}

	for (int i = 0; i < 10; i++)
	{
		if (item[i] == nullptr)
		{
			break;
		}
		item[i]->Draw();
	}

}

//シーンの変更処理
AbstractScene* GameMainScene::ChangeScene() {
	return this;
}