//
// BG.cpp
//

#include "SuitonMagic.h"

using namespace HE;

void SuitonMagic::OnCollision()
{
	areasprite_.params.pos.x = Random::GetRandom(0.0f, 1280.0f - areasprite_.params.siz.x);
	areasprite_.params.pos.y = (-120.0f);
}


Math::Rectangle SuitonMagic::GetCollision()
{
	if (areasprite_.IsHidden()) {
		return Math::Rectangle(0, 0, 0, 0);
	}
	Math::Rectangle collision;
	collision.x = (long)areasprite_.params.pos.x;
	collision.y = (long)areasprite_.params.pos.y;
	collision.width = (long)areasprite_.params.siz.x;
	collision.height = (long)areasprite_.params.siz.y;

	return collision;
}

void SuitonMagic::Load()
{

	areasprite_ = Sprite("suitonmagic.png");
	RenderingPath->AddSprite(&areasprite_, 100);
	areasprite_.SetHidden(true); // 最初は非表示

	se_ = Sound("se_enemy_water.wav", Sound::LoopCount::BGM); 
}

void SuitonMagic::Initialize()
{

	areasprite_.params.siz = Math::Vector2(1280.0f, 150.0f);
	areasprite_.params.pos = Math::Vector2(1280.0f, 370.0f);

}

void SuitonMagic::Update(float deltaTime)
{
	alltime_.Update(deltaTime);
	float elapsed = alltime_.GetElapsedTime();

	// 8秒経過で表示開始
	if (!isSprite_ && elapsed >= 30.0f) {
		isSprite_ = true;
		areasprite_.SetHidden(false);
		se_.Play(); // SEを再生
		areasprite_.params.pos.x = 1280.0f; // 右端に再セット（必要なら）
	}

	// 表示中のみ左に移動
	if (isSprite_) {
		areasprite_.params.pos.x -= 800.0f * deltaTime; // 左へ移動
	}

	// 10秒経過で非表示
	if (isSprite_ && elapsed >= 34.0f) {
		isSprite_ = false;
		areasprite_.SetHidden(true);
		se_.Stop(); // SEを停止
	}
}