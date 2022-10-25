#include "DxLib.h"
#include "KeyManager.h"

char KeyManager::oldKey[256];
char KeyManager::nowKey[256];

int KeyManager::oldMouse;
int KeyManager::nowMouse;

void KeyManager::Update()
{

	for (int i = 0; i < 256; i++) 
	{
		oldKey[i] = nowKey[i];
	}
	if (GetHitKeyStateAll(nowKey) == -1)
	{
		throw - 1;
	}

	oldMouse = nowMouse;
	nowMouse = GetMouseInput();


}

bool KeyManager::OnKeyClicked(int Key)
{
	//ボタンを押した瞬間
	bool ret = (nowKey[Key] == 1) && (oldKey[Key] != 1);
	return ret;
}

bool KeyManager::OnKeyReleased(int Key)
{
	//ボタンを離した瞬間
	bool ret = (nowKey[Key] != 1) && (oldKey[Key] == 1);
	return ret;
}

bool KeyManager::OnKeyPressed(int Key)
{
	//ボタンを押し続ける間
	bool ret = (nowKey[Key] == 1);
	return ret;
}

bool KeyManager::OnMouseClicked(int Key)
{
	bool ret = ((nowMouse & Key) && (~oldMouse & Key));
	return ret;
}

bool KeyManager::OnMouseReleased(int Key)
{
	bool ret = ((~nowMouse & Key) && (oldMouse & Key));
	return ret;
}

bool KeyManager::OnMousePressed(int Key)
{
	bool ret = (nowMouse & Key);
	return ret;
}
