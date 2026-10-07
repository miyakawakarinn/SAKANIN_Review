//
// GameOverScene.cpp
//

#include "Gameover.h"
#include "DontDestroyOnLoad.h"

using namespace HE;

// initialize member variables.
Gameover::Gameover()
{

}

// rearrange UI to fit the size.
void Gameover::ResizeLayout()
{
    Scene::ResizeLayout();



}

// load resources.
void Gameover::Load()
{
    bg_ = Sprite("haikeiv06.png");
    RenderingPath->AddSprite(&bg_, -100); // ”wŒi‚Ì•\Ž¦—Dæ“x‚ðÝ’è
    sprite_ = Sprite("genin_result.png");
    RenderingPath->AddSprite(&sprite_, 0);
    select_ = Sprite("Kunai.png");
    RenderingPath->AddSprite(&select_, 1);

    //result_time_ = SpriteFont("YujiMai-Regular.ttf");
    RenderingPath->AddFont(&result_time_, 1000);

    se_select_ = Sound("se_button_select.wav", Sound::LoopCount::SE);
	bgm_ = Sound("jingle_result.wav", Sound::LoopCount::BGM);
	bgm_.Play();

    Scene::Load();
}

// initialize a variables.
void Gameover::Initialize()
{
    bg_.params.siz = sprite_.GetTextureSize();
    bg_.params.pos = Math::Vector2(0.0f, 0.0f);
    sprite_.params.siz = sprite_.GetTextureSize();
    sprite_.params.pos = Math::Vector2(0.0f, 0.0f);

    // ‚­‚È‚¢‰æ‘œ‚ÌƒTƒCƒY‚ðKunai.png‚ÌƒTƒCƒY‚ÉC³
    select_.params.siz = select_.GetTextureSize();
    select_.params.pos = Math::Vector2(330.0f, 493.0f);

    result_time_.SetText(std::to_wstring((int)DontDestroy.elapsedTime_));
    result_time_.params.posX = 540.0f;
    result_time_.params.posY = 250.0f;
    result_time_.params.size = 150;
    result_time_.params.color = Color(255, 255, 255);
}

// releasing resources required for termination.
void Gameover::Terminate()
{

}

// updates the scene.
void Gameover::Update(float deltaTime)
{
    if (InputSystem.Keyboard.wasPressedThisFrame.Enter) {
        SceneManager.SetNextScene(NextScene::Title);
    }
    // ‚­‚È‚¢‚ÌˆÚ“®,  ‰æ–Ê‚Ì‘JˆÚ
    if (InputSystem.Keyboard.wasPressedThisFrame.Down) {
        selectnum_ += 1;
        se_select_.Stop();
        se_select_.Play();
        if (selectnum_ > 1) {
            selectnum_ = 0; 
        }
    }
    if (InputSystem.Keyboard.wasPressedThisFrame.Up) {
        selectnum_ -= 1;
        se_select_.Stop();
        se_select_.Play();
        if (selectnum_ < 0) {
            selectnum_ = 1; 
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