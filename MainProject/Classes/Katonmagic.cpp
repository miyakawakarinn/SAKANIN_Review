//
// BG.cpp
//

#include "KatonMagic.h"

using namespace HE;

void KatonMagic::OnCollision()
{
	areasprite_.params.pos.x = Random::GetRandom(0.0f, 1280.0f - areasprite_.params.siz.x);
	areasprite_.params.pos.y = (-120.0f);
}


Math::Rectangle KatonMagic::GetCollision()
{
	if (areasprite_.IsHidden()) {
		return Math::Rectangle(0, 0, 0, 0);
	}
	Math::Rectangle collision;
	collision.x = (long)areasprite_.params.pos.x ;
	collision.y = (long)areasprite_.params.pos.y;
	collision.width = (long)areasprite_.params.siz.x;
	collision.height = (long)areasprite_.params.siz.y;

	return collision;
}

void KatonMagic::Load()
{

	areasprite_ = Sprite("Katon.png");
	RenderingPath->AddSprite(&areasprite_, -21);
	areasprite_.SetHidden(true); // 最初は非表示

	se_ = Sound("se_enemy_fire.wav", Sound::LoopCount::BGM); 
}

void KatonMagic::Initialize()
{

	areasprite_.params.siz = Math::Vector2(170.0f, 170.0f); // 背景のサイズを設定
	areasprite_.params.pos = Math::Vector2(890.0f, 180.0f);

}

void KatonMagic::Update(float deltaTime)
{
	alltime_.Update(deltaTime);
	float elapsed = alltime_.GetElapsedTime();

	// 8秒経過で表示開始
	if (!isSprite_ && elapsed >= 20.0f) {
		isSprite_ = true;
		areasprite_.SetHidden(false);
		se_.Play(); // SEを再生
	}

	// 10秒経過で非表示
	if (isSprite_ && elapsed >= 24.5f) {
		isSprite_ = false;
		areasprite_.SetHidden(true);
		se_.Stop(); // SEを停止
	}
}//忍者の位置を直して完成