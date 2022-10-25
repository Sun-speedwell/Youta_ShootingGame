#include "GameMainScene.h"
GameMainScene::GameMainScene()
{
	T_location Location = T_location{ 20,100 };
	player = new Player(Location);
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
}

//描画に関することを実装する
void GameMainScene::Draw() const {
	player->Draw();
}

//シーンの変更処理
AbstractScene* GameMainScene::ChangeScene() {
	return this;
}