//
// BG.cpp
//

#include "Suiton.h"
#include <random>

using namespace HE;

void Suiton::Load()
{

	sprite_ = Sprite("SuitonEnemy.png");
	RenderingPath->AddSprite(&sprite_, 100);
	sprite_.SetHidden(true); // 最初は非表示
	magicsprite_ = Sprite("hit_blue_v01.png"); // 当たり判定予告のスプライト
	RenderingPath->AddSprite(&magicsprite_, -22); // 当たり判定予告のスプライトの表示
	magicsprite_.SetHidden(true); // 最初は非表示
}

void Suiton::Initialize()
{

	sprite_.params.siz = Math::Vector2(100.0f, 100.0f); // 背景のサイズを設定
	sprite_.params.pos = Math::Vector2(150.0f, 430.0f);
	magicsprite_.params.siz = Math::Vector2(1280.0f, 170.0f); // 当たり判定予告のスプライトのサイズを設定
	magicsprite_.params.pos = Math::Vector2(0.0f, 360.0f); // 当たり判定予告のスプライトの位置を設定

}

void Suiton::Update(float deltaTime)
{
	// 乱数生成器の初期化（staticで1回だけ初期化）
	static std::random_device rd;
	static std::mt19937 mt(rd());
	static std::uniform_int_distribution<int> dist(0, 3); // 0~7まで
	alltime_.Update(deltaTime);
	float elapsed = alltime_.GetElapsedTime();
	if (!isSprite_ && elapsed >= 27.0f) {
		int random = dist(mt);
		RandomPos(random); // ここでランダムな値を渡す
		isSprite_ = true;
		sprite_.SetHidden(false); // 
		magicsprite_.SetHidden(false);
	}
	if (isSprite_ && elapsed >= 33.5f) {
		magicsprite_.SetHidden(true); // 当たり判定予告のスプライトを非表示
	}
	if (isSprite_ && elapsed >= 35.0f) {
		isSprite_ = false;
		sprite_.SetHidden(true);

	}

}
void Suiton::RandomPos(int randomNum) {
	switch (randomNum) {
	case 0:
		sprite_.params.pos = Math::Vector2(103.0f, 92.0 - 10.0f);
		magicsprite_.params.pos = Math::Vector2(0.0f, 83.0 - 10.0 - 62.0f);
		break;
	case 1:
		sprite_.params.pos = Math::Vector2(103.0f, 170.0 + 92.0f);
		magicsprite_.params.pos = Math::Vector2(0.0f, 170.0 + 83.0 - 62.0f);
		break;
	case 2:
		sprite_.params.pos = Math::Vector2(103.0f, 340.0 + 92.0f);
		magicsprite_.params.pos = Math::Vector2(0.0f, 340.0 + 83.0 - 62.0f);
		break;
	case 3:
		sprite_.params.pos = Math::Vector2(103.0f, 517.0 + 92.0f);
		magicsprite_.params.pos = Math::Vector2(0.0f, 517.0 + 83.0 - 62.0f);
		break;
	}//ちょっと攻撃予告がずれているので直してね
}
