
#include "AllTime.h"

using namespace HE;
AllTime::AllTime()
{
	
}
void AllTime::ResizeLayout()
{
	Scene::ResizeLayout();
}
void AllTime::Load()
{

}
void AllTime::Initialize()
{
	elapsedTime_ = 0.0f; 
}
void AllTime::Terminate()
{

}
void AllTime::Update(float deltaTime)
{
	elapsedTime_ += deltaTime; // deltaTimeはフレームごとの経過秒数

	//if (elapsedTime_ >= 30.0f) {//制限時間はここで変更
	//	SceneManager.SetNextScene(NextScene::Gameclear);
	//	return; // 以降の処理をスキップ
	//}

}//メインシーンに上の時間のやつを直接書き込んでね