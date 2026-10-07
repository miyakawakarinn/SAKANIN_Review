//
// Katon.cpp
//

#include "Katon.h"
#include <random>

using namespace HE;


void Katon::Load()
{
	sprite_ = Sprite("KatonEnemy.png");
	RenderingPath->AddSprite(&sprite_, -20);// 忍者の表示
	sprite_.SetHidden(true); // 最初は非表示
	magicsprite_ = Sprite("hit_red_v01.png"); // 当たり判定予告のスプライト
	RenderingPath->AddSprite(&magicsprite_, -22); // 当たり判定予告のスプライトの表示
	magicsprite_.SetHidden(true); // 最初は非表示
}

void Katon::Initialize()
{
	sprite_.params.siz = Math::Vector2(100.0f, 100.0f); 
	sprite_.params.pos = Math::Vector2(936.0f, 253.0f);
	magicsprite_.params.siz = Math::Vector2(170.0f, 170.0f); // 当たり判定予告のスプライトのサイズを設定
	magicsprite_.params.pos = Math::Vector2(903.0f, 185.0f); // 当たり判定予告のスプライトの位置を設定

}

void Katon::Update(float deltaTime)
{

    // 乱数生成器の初期化（staticで1回だけ初期化）
    static std::random_device rd;
    static std::mt19937 mt(rd());
	static std::uniform_int_distribution<int> dist(0, 7); // 0~7まで

	alltime_.Update(deltaTime);
	float elapsed = alltime_.GetElapsedTime();
	if (!isSprite_ && elapsed >= 17.0f) {
		int random = dist(mt);
		RandomPos(random); // ここでランダムな値を渡す
		isSprite_ = true;
		sprite_.SetHidden(false);
		magicsprite_.SetHidden(false); // 当たり判定予告のスプライトを表示
	}
	if (isSprite_ && elapsed >= 24.5f) {
		magicsprite_.SetHidden(true); // 当たり判定予告のスプライトを非表示
	}
	if (isSprite_ && elapsed >= 26.0f) {
		isSprite_ = false;
		sprite_.SetHidden(true);
	}

}

void Katon::RandomPos(int randomNum) {

	switch (randomNum) {

	case 0:
		sprite_.params.pos = Math::Vector2(255.0+74.0f, 92.0-10.0f);
		magicsprite_.params.pos = Math::Vector2(245.0 + 81.0 - 33.0f, 83.0 - 10.0 - 65.0f); 
		break;
	case 1:
		sprite_.params.pos = Math::Vector2(655.0 + 74.0f, -10.0 + 92.0f);
		magicsprite_.params.pos = Math::Vector2(645.0 + 81.0 - 33.0f, -10.0 + 83.0 - 65.0f); 
		break;
	case 2:
		sprite_.params.pos = Math::Vector2(355.0 + 74.0f, 170.0 + 92.0f);
		magicsprite_.params.pos = Math::Vector2(345.0 + 81.0 - 33.0f, 170.0 + 83.0 - 65.0f);
		break;
	case 3:
		sprite_.params.pos = Math::Vector2(855.0 + 74.0f, 170.0 + 92.0f);
		magicsprite_.params.pos = Math::Vector2(845.0 + 81.0 - 33.0f, 170.0 + 83.0 - 65.0f);
		break;
	case 4:
		sprite_.params.pos = Math::Vector2(255.0 + 74.0f, 340.0 + 92.0f);
		magicsprite_.params.pos = Math::Vector2(245.0 + 81.0 - 33.0f, 340.0 + 83.0 - 65.0f);
		break;
	case 5:
		sprite_.params.pos = Math::Vector2(555.0 + 74.0f, 340.0 + 92.0f);
		magicsprite_.params.pos = Math::Vector2(545.0 + 81.0 - 33.0f, 340.0 + 83.0 - 65.0f);
		break;
	case 6:
		sprite_.params.pos = Math::Vector2(255.0 +74.0f, 517.0 + 92.0f);
		magicsprite_.params.pos = Math::Vector2(245.0 + 81.0 - 33.0f, 517.0 + 83.0 - 65.0f);
	case 7:
		sprite_.params.pos = Math::Vector2(855.0 + 74.0f, 517.0 + 92.0f);
		magicsprite_.params.pos = Math::Vector2(845.0 + 81.0 - 33.0f, 517.0 + 83.0 - 65.0f);
		break;
	}


}