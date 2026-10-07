//
// GameOverScene.cpp
//

#include "Title.h"

using namespace HE;

// initialize member variables.
Title::Title()
{

}

// rearrange UI to fit the size.
void Title::ResizeLayout()
{
    Scene::ResizeLayout();



}

// load resources.
void Title::Load()
{//画像の読み込み
    sprite_  = Sprite("Title.png");
	button1_ = Sprite("menu.png");
	//button2_ = Sprite("corule.png");
    //button3_ = Sprite("end.png");
    //ボタンの位置を設定
	select_  = Sprite("Kunai.png");

    //画像表示の優先度
    RenderingPath->AddSprite(&sprite_, -100);
	RenderingPath->AddSprite(&button1_, 300);
    //RenderingPath->AddSprite(&button2_, 150);
    //RenderingPath->AddSprite(&button3_, 175);
	RenderingPath->AddSprite(&select_,  200);

    bgm_ = Sound("bgm_title.wav", Sound::LoopCount::BGM);
    bgm_.Play();
	se_start_   = Sound("se_button_start.wav", Sound::LoopCount::BGM);
	se_setumei_  = Sound("se_button_rule.wav", Sound::LoopCount::BGM);
    se_select_  = Sound("se_button_select.wav", Sound::LoopCount::SE);

    Scene::Load();
}

// initialize a variables.
void Title::Initialize()
{

    sprite_.params.siz = sprite_.GetTextureSize();
    sprite_.params.pos = Math::Vector2(0.0f, 0.0f);
	button1_.params.siz = button1_.GetTextureSize();
	button1_.params.pos = Math::Vector2(257.0f, 438.5f);
	select_.params.siz = select_.GetTextureSize();
    select_.params.pos = Math::Vector2(122.0f, 465.5f);
    

}//上から順に、ゲーム開始、説明、終了

// releasing resources required for termination.
void Title::Terminate()
{

}

// updates the scene.
void Title::Update(float deltaTime)
{
    if (InputSystem.Keyboard.wasPressedThisFrame.Down) {
		se_select_.Stop();
        se_select_.Play();
		selectnum_ += 1;
        if (selectnum_ > 2) {
            selectnum_ = 0; 

		}
	}
    if (InputSystem.Keyboard.wasPressedThisFrame.Up) {
		se_select_.Stop();
        se_select_.Play();
        selectnum_ -= 1;
        if (selectnum_ < 0) {
            selectnum_ = 2; 
        }
	}
    if (selectnum_ == 0) {
        select_.params.pos = Math::Vector2(122.0f, 465.5f);
        if ( InputSystem.Keyboard.wasPressedThisFrame.Enter) {
			se_start_.PlayFromTop();
            SceneManager.SetNextScene(NextScene::MainScene);
		}
    }
    if (selectnum_ == 1) {
        select_.params.pos = Math::Vector2(152.0f, 550.5f);
        if (InputSystem.Keyboard.wasPressedThisFrame.Enter) {
            se_setumei_.PlayFromTop();
            SceneManager.SetNextScene(NextScene::setumei);
		}
    }
    if (selectnum_ == 2) {
        select_.params.pos = Math::Vector2(152.0f, 550.5+85.0f);
        if (InputSystem.Keyboard.wasPressedThisFrame.Enter) {
            wi::jobsystem::ShutDown();
            PostQuitMessage(0);
        }
	}


    Scene::Update(deltaTime);
}//ちゃっとGPTを見ながら効果音の保存処理を進めてね