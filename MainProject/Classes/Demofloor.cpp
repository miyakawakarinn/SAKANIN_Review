//Demofloor.cpp
#include "Demofloor.h"
#include "Player.h"

using namespace HE;

Math::Rectangle Demofloor::GetCollision()
{
    Math::Rectangle collision;
    collision.x = (long)spritefloor_.params.pos.x;
    collision.y = (long)spritefloor_.params.pos.y;
    collision.width = (long)spritefloor_.params.siz.x;
    collision.height = (long)spritefloor_.params.siz.y;

    return collision;
}

void Demofloor::OnCollision()
{
    //if (playerPtr_) {
    //    // プレイヤーの上下移動を止める
    //    playerPtr_->StopVerticalMovement();
    //}
}

void Demofloor::Load()
{
    spritefloor_ = Sprite("floor.png");
    RenderingPath->AddSprite(&spritefloor_, -50);
}

void Demofloor::Initialize(Math::Vector2 Initialposition,float floorsizex)
{
    spritefloor_.params.siz = Math::Vector2(floorsizex, 20.0f);
    spritefloor_.params.pos = Initialposition;

}

void Demofloor::Update()
{

}
HE::Math::Vector2 Demofloor::GetPosition() const {
    auto p = spritefloor_.params.pos;
    // HE::Math::Vector2(float x, float y) というコンストラクタがある前提
    return HE::Math::Vector2{ p.x, p.y };
}