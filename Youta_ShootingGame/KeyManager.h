#pragma once
class KeyManager
{
private:
	//static�ɂ��邱�ƂŃI�u�W�F�N�g���g�킸�ɂ���
	static char oldKey[256];
	static char nowKey[256];
	static int oldMouse;
	static int nowMouse;
private:
	KeyManager() = default;

public:
	static void Update();//�L�[�̃A�b�v�f�[�g
	static bool OnKeyClicked(int Key);//�����Ă��
	static bool OnKeyReleased(int Key);//�L�[��������Ă邩
	static bool OnKeyPressed(int Key);//���������Ă��邩

	static bool OnMouseClicked(int Key);//�����Ă��
	static bool OnMouseReleased(int Key);//�L�[��������Ă邩
	static bool OnMousePressed(int Key);//���������Ă��邩
};

