#pragma once
class KeyManager
{
private:
	//staticにすることでオブジェクトを使わずにすむ
	static char oldKey[256];
	static char nowKey[256];
	static int oldMouse;
	static int nowMouse;
private:
	KeyManager() = default;

public:
	static void Update();//キーのアップデート
	static bool OnKeyClicked(int Key);//押してる間
	static bool OnKeyReleased(int Key);//キーが離されてるか
	static bool OnKeyPressed(int Key);//押し続けているか

	static bool OnMouseClicked(int Key);//押してる間
	static bool OnMouseReleased(int Key);//キーが離されてるか
	static bool OnMousePressed(int Key);//押し続けているか
};

