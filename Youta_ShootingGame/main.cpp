#include "DxLib.h"
#include "SceneManager.h"
#include "GameMainScene.h"
#include "KeyManager.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) {

	// タイトルを test に変更
	SetMainWindowText("シューティングゲーム");

	ChangeWindowMode(TRUE);		// ウィンドウモードで起動

	if (DxLib_Init() == -1) return -1;	// DXライブラリの初期化処理

	SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする

	SetFontSize(20);		// 文字サイズを設定

	SceneManager sceneMng(dynamic_cast<AbstractScene*>(new GameMainScene()));

	// ゲームループ
	while (ProcessMessage() == 0) {

		// 入力キー取得
		//g_OldKey = g_NowKey;
		//g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		//g_KeyFlg = g_NowKey & ~g_OldKey;
		
			ClearDrawScreen();

			KeyManager::Update();
			if(KeyManager::OnMousePressed(MOUSE_INPUT_LEFT))
			{
				DrawFormatString(200, 200, 0xffffff, "あ");
			}

			sceneMng.Update();
			sceneMng.Draw();//シーンの更新処理
			if (sceneMng.ChangeScene() == nullptr) {

				DxLib_End();	// DXライブラリ使用の終了処理

				return 0;	// ソフトの終了
			
			}

				ScreenFlip();
				
		}

	DxLib_End();	// DXライブラリ使用の終了処理

	return 0;	// ソフトの終了

}

	