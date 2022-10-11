#include "SceneManager.h"

// メンバ変数の値を書き換えるのがアップデート関数
void SceneManager::Update() {
    // 現在シーンのアップデートを実行
    mScene->Update();
}

// 描画処理のみを行う関数
void SceneManager::Draw() const {
    // 現在シーンの描画関数を実行
    mScene->Draw();
}

//シーンの変更処理
AbstractScene* SceneManager::ChangeScene() {
    AbstractScene* nextScene = mScene->ChangeScene();

    if (nextScene != mScene) {
        delete mScene;
        mScene = nextScene;
    }

    return nextScene;
}