
//
// GameOverScene.cpp
//

#include "setumei.h"

using namespace HE;

// initialize member variables.
setumei::setumei()
{

}

// rearrange UI to fit the size.
void setumei::ResizeLayout()
{
    Scene::ResizeLayout();



}

// load resources.
void setumei::Load()
{
    sprite_ = Sprite("rule.png");
    RenderingPath->AddSprite(&sprite_, -100);


    Scene::Load();
}

// initialize a variables.
void setumei::Initialize()
{

    sprite_.params.siz = sprite_.GetTextureSize();
    sprite_.params.pos = Math::Vector2(0.0f, 0.0f);
}

// releasing resources required for termination.
void setumei::Terminate()
{

}

// updates the scene.
void setumei::Update(float deltaTime)
{
    if (InputSystem.Keyboard.wasPressedThisFrame.Enter) {
        SceneManager.SetNextScene(NextScene::Title);
    }


    Scene::Update(deltaTime);
}