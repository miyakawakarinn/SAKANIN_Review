//
// BG.cpp
//

#include "KatonHusuma.h"

using namespace HE;

void KatonHusuma::Load()
{
	sprite_ = Sprite("husuma_kawa.png");
	RenderingPath->AddSprite(&sprite_, -30);
	for (int i = 0; i < 8; ++i) {
		room_[i] = Sprite("fusuma_red.png");
		RenderingPath->AddSprite(&room_[i], -50);
	}

	se_ = Sound("se_fusuma_open.wav", 0); // 1回だけ再生
}

void KatonHusuma::Initialize()
{
	sprite_.params.siz = Math::Vector2(256.0f, 256.0f);
	sprite_.params.pos = Math::Vector2(936.0f, 253.0f);
	sprite_.params.enableDrawRect(Rectf(
		0, 0, 256.0f, 256.0f
	));
	for (int i = 0; i < 8; ++i) {
		room_[i].params.siz = Math::Vector2(125.0f, 125.0f);
	}
	//ふすまの内側の位置
	room_[0].params.pos = Math::Vector2(320.0f,55.0f);
	room_[1].params.pos = Math::Vector2(720.0f,55.0f);
	room_[2].params.pos = Math::Vector2(420.0f, 232.0f);
	room_[3].params.pos = Math::Vector2(920.0f, 232.0f);
	room_[4].params.pos = Math::Vector2(320.0f, 405.0f);
	room_[5].params.pos = Math::Vector2(620.0f, 405.0f);
	room_[6].params.pos = Math::Vector2(320.0f, 582.0f);
	room_[7].params.pos = Math::Vector2(920.0f, 582.0f);

	isPlaying = false; // 初期状態ではアニメーションは再生されていない

}

void KatonHusuma::Update(float deltaTime)
{
	alltime_.Update(deltaTime);
		if (alltime_.GetElapsedTime() >= 16.8f) { // 5秒経過でアニメーション開始
			if (isPlaying == false) {
				isPlaying = true;
				se_.PlayFromTop(); // SEを再生
				sprite_.anim = Sprite::Anim();
				sprite_.anim.repeatable = false;                       // ループするかしないか
				sprite_.anim.drawRectAnim.frameRate = 15;              // アニメーションの速度
				sprite_.anim.drawRectAnim.frameCount = 12;             // 画像にアニメーションが何コマあるか
				sprite_.anim.drawRectAnim.horizontalFrameCount = 6;    // 横に並んでいるコマ数
			}
		}
}