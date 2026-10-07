#include "Obstacle.h"

using namespace HE;


void Obstacle::OnCollision()
{
    sprite_.params.pos.x = Random::GetRandom(0.0f, 1280.0f - sprite_.params.siz.x);
    sprite_.params.pos.y = (-120.0f);
}


Math::Rectangle Obstacle::GetCollision()
{
    Math::Rectangle collision;
    collision.x = (long)sprite_.params.pos.x;
    collision.y = (long)sprite_.params.pos.y;
    collision.width = (long)sprite_.params.siz.x;
    collision.height = (long)sprite_.params.siz.y;

    return collision;
}

void Obstacle::Load()
{


    sprite_ = Sprite("makibisi.png");//ここで画像を変えるよ！！
    RenderingPath->AddSprite(&sprite_, -30);



}

void Obstacle::Initialize(Math::Vector2 Initialposition)
{

    sprite_.params.siz = Math::Vector2(80.0f, 30.0f);//ここで画像のサイズ変更
    sprite_.params.pos = Initialposition;
    sprite_.params.enableDrawRect(Rectf(
        0, 0, sprite_.params.siz.x, sprite_.params.siz.y
    ));

    Inversion = 1;

    //きえるかどうかのbool
//消えたかどうかのbool
//何秒で消えるか
    //アクティブタイム
}

void Obstacle::Update(Math::Vector2 Setposition)
{
    
}