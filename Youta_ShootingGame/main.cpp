#include "DxLib.h"
#include "SceneManager.h"
#include "GameMainScene.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) {

	// �^�C�g���� test �ɕύX
	SetMainWindowText("�u���b�N����");

	ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��

	if (DxLib_Init() == -1) return -1;	// DX���C�u�����̏���������

	SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���

	SetFontSize(20);		// �����T�C�Y��ݒ�

	SceneManager sceneMng(dynamic_cast<AbstractScene*>(new GameMainScene()));

	// �Q�[�����[�v
	while (ProcessMessage() == 0) {

		// ���̓L�[�擾
		//g_OldKey = g_NowKey;
		//g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		//g_KeyFlg = g_NowKey & ~g_OldKey;
		
			ClearDrawScreen();
			sceneMng.Draw();//�V�[���̍X�V����
			if (sceneMng.ChangeScene() != nullptr) {

				DxLib_End();	// DX���C�u�����g�p�̏I������

				return 0;	// �\�t�g�̏I��
			
			}

				ScreenFlip();
		}

}

	