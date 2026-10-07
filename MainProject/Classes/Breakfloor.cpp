//Demofloor.cpp
#include "Breakfloor.h"
#include "Player.h"


using namespace HE;

Math::Rectangle Breakfloor::GetCollision()
{
    if (isBroken_) return Math::Rectangle(); // 床が壊れている場合は衝突判定を返さない
        Math::Rectangle collision;
        collision.x = (long)spritefloor_.params.pos.x;
        collision.y = (long)spritefloor_.params.pos.y;
        collision.width = (long)spritefloor_.params.siz.x;
        collision.height = (long)spritefloor_.params.siz.y;

        return collision;
    }

void Breakfloor::OnCollision()
{

}

void Breakfloor::Load()
{
    spritefloor_ = Sprite("floor_brake.png");
    RenderingPath->AddSprite(&spritefloor_, -50);

	se_break_ = Sound("se_stage_break.wav", Sound::LoopCount::SE); // 床が壊れる音の読み込み

}

void Breakfloor::Initialize(Math::Vector2 Initialposition,float breaktime,float breakfloorsizex)
{
	breaktime_ = breaktime; // 壊れるまでの時間を設定
	isBroken_ = false; // 初期状態では壊れていない
    spritefloor_.params.siz = Math::Vector2(breakfloorsizex, 20.0f);//本来は300.0f,20.0f
    spritefloor_.params.pos = Initialposition;
}

void Breakfloor::Update(float deltaTime)
{
	//タイマーの時間を取得して、壊れるまでの時間を設定する
    alltime_.Update(deltaTime);
    float elapsed = alltime_.GetElapsedTime();
    if (!isBroken_ && elapsed >= breaktime_) {
        // 壊れる時間に達したら床を壊す
		se_break_.Play(); 
        isBroken_ = true;
        spritefloor_.SetHidden(true);
    }

}
HE::Math::Vector2 Breakfloor::GetPosition() const {
    auto p = spritefloor_.params.pos;
    // HE::Math::Vector2(float x, float y) というコンストラクタがある前提
    return HE::Math::Vector2{ p.x, p.y };
}