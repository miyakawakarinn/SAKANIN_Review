//
// GameOverScene.cpp
//

#include "Gameclear.h"
#include "DontDestroyOnLoad.h"

using namespace HE;

// initialize member variables.
Gameclear::Gameclear()
{

}

// rearrange UI to fit the size.
void Gameclear::ResizeLayout()
{
    Scene::ResizeLayout();



}

// load resources.
void Gameclear::Load()
{
	bg_ = Sprite("haikeiv06.png");
	RenderingPath->AddSprite(&bg_, -100); // 背景の表示優先度を設定
    sprite_ = Sprite("Gameclear.png");
    RenderingPath->AddSprite(&sprite_, 0);
    select_ = Sprite("Kunai.png");
    RenderingPath->AddSprite(&select_, 1);

    //result_time_ = SpriteFont("result.ttf");
    RenderingPath->AddFont(&result_time_, 1000);

    se_select_ = Sound("se_button_select.wav", Sound::LoopCount::SE);
    bgm_ = Sound("bgm_result.wav", Sound::LoopCount::BGM);
    bgm_.Play();

    Scene::Load();
}

// initialize a variables.
void Gameclear::Initialize()
{
    bg_.params.siz = sprite_.GetTextureSize();
    bg_.params.pos = Math::Vector2(0.0f, 0.0f);
    sprite_.params.siz = sprite_.GetTextureSize();
    sprite_.params.pos = Math::Vector2(0.0f, 0.0f);

    // くない画像のサイズをKunai.pngのサイズに修正
    select_.params.siz = select_.GetTextureSize();
    select_.params.pos = Math::Vector2(330.0f, 493.0f);

    result_time_.SetText(std::to_wstring((int)DontDestroy.elapsedTime_));
    result_time_.params.posX = 540.0f;
    result_time_.params.posY = 250.0f;
    result_time_.params.size = 150;
    result_time_.params.color = Color(255, 255, 255);
}

// releasing resources required for termination.
void Gameclear::Terminate()
{

}

// updates the scene.
void Gameclear::Update(float deltaTime)
{
    if (InputSystem.Keyboard.wasPressedThisFrame.Enter) {
        SceneManager.SetNextScene(NextScene::Title);
    }
	// くないの移動,  画面の遷移
    if (InputSystem.Keyboard.wasPressedThisFrame.Down) {
        selectnum_ += 1;
        se_select_.Stop();
        se_select_.Play();
        if (selectnum_ > 1) {
            selectnum_ = 0; // 3つ目のボタンを超えたら最初に戻る
        }
    }
    if (InputSystem.Keyboard.wasPressedThisFrame.Up) {
        selectnum_ -= 1;
        se_select_.Stop();
        se_select_.Play();
        if (selectnum_ < 0) {
            selectnum_ = 1; // 最初のボタンを超えたら最後に戻る
        }
    }
    if (selectnum_ == 0) {
        select_.params.pos = Math::Vector2(330.0f, 493.0f);
        if (InputSystem.Keyboard.wasPressedThisFrame.Enter) {
            SceneManager.SetNextScene(NextScene::MainScene);
        }
    }
    if (selectnum_ == 1) {
        select_.params.pos = Math::Vector2(330.0f, 605.f);
        if (InputSystem.Keyboard.wasPressedThisFrame.Enter) {
            SceneManager.SetNextScene(NextScene::Title);
        }
    }

    Scene::Update(deltaTime);
}