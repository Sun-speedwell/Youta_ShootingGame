#include "GameMainScene.h"
GameMainScene::GameMainScene()
{
	T_location Location = T_location{ 20,100 };
	player = new Player(Location);
}

//�`��ȊO�̍X�V����������
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

//�`��Ɋւ��邱�Ƃ���������
void GameMainScene::Draw() const {
	player->Draw();
}

//�V�[���̕ύX����
AbstractScene* GameMainScene::ChangeScene() {
	return this;
}