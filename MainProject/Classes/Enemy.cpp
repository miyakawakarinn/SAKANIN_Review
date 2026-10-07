//Enemy.cpp
#include "Enemy.h"

using namespace HE;


void Enemy::OnCollision()
{
    sprite_.params.pos.x = Random::GetRandom(0.0f, 1280.0f - sprite_.params.siz.x);
    sprite_.params.pos.y = (-120.0f);
}


Math::Rectangle Enemy::GetCollision()
{
    Math::Rectangle collision;
    collision.x = (long)sprite_.params.pos.x;
    collision.y = (long)sprite_.params.pos.y;
    collision.width = (long)sprite_.params.siz.x;
    collision.height = (long)sprite_.params.siz.y;

    return collision;
}

void Enemy::Load()
{


    sprite_ = Sprite("syuriken_02.png");//ここで画像を変えるよ！！
    RenderingPath->AddSprite(&sprite_, -30);
    sprite_.params.enableDrawRect(Rectf(0.0f, 0.0f, 512.0f, 512.0f));
	sprite_.params.siz = Math::Vector2(64.0f, 64.0f); // サイズを設定

}
void Enemy::Initialize(Math::Vector2 Initialposition)
{
    sprite_.params.pos = Initialposition;
    Inversion = 1.0f;

    sprite_.anim = Sprite::Anim();
    sprite_.anim.repeatable = true;                       // ループするかしないか
    sprite_.anim.drawRectAnim.frameRate = 15;              // アニメーションの速度
    sprite_.anim.drawRectAnim.frameCount = 5;             // 画像にアニメーションが何コマあるか
    sprite_.anim.drawRectAnim.horizontalFrameCount = 5;   // 横に並んでいるコマ数
}
void Enemy::Update(float minX, float maxX)
{
    minX_ = minX;
    maxX_ = maxX;
    sprite_.params.pos.x += Inversion * 2.0f;
    if (sprite_.params.pos.x < minX_) {
        Inversion = 1.0f;
        sprite_.params.pos.x = minX_;
    }
    else if (sprite_.params.pos.x > maxX_) {
        Inversion = -1.0f;
        sprite_.params.pos.x = maxX_;
    }
}
