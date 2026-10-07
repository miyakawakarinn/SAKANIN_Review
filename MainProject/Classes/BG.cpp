//
// BG.cpp
//

#include "BG.h"

using namespace HE;

void BG::Load()
{

    sprite_ = Sprite("haikeiv06.png");
    RenderingPath->AddSprite(&sprite_, -1000);
	spritewall1_ = Sprite("wall.png");
	RenderingPath->AddSprite(&spritewall1_, -990);
	spritewall2_ = Sprite("wall.png");
	RenderingPath->AddSprite(&spritewall2_, -1000);
	sprite30_ = Sprite("30second.png");
	RenderingPath->AddSprite(&sprite30_, 1000);
	sprite30_.SetHidden(true); // 最初は非表示
	sprite10_ = Sprite("10second.png");
	RenderingPath->AddSprite(&sprite10_, 1000);
	sprite10_.SetHidden(true); // 最初は非表示
}

void BG::Initialize()
{

	sprite_.params.siz = Math::Vector2(1280.0f, 720.0f); // 背景のサイズを設定
    sprite_.params.pos = Math::Vector2(0.0f, 0.0f);

	spritewall1_.params.siz = Math::Vector2(40.0f, 720.0f); // 壁のサイズを設定
	spritewall1_.params.pos = Math::Vector2(0.0f, 0.0f);
	spritewall2_.params.siz = Math::Vector2(40.0f, 720.0f); // 壁のサイズを設定
	spritewall2_.params.pos = Math::Vector2(1240.0f, 0.0f); // 壁の位置を設定

	sprite30_.params.siz = Math::Vector2(512.0f, 512.0f); // 30秒のスプライトのサイズを設定
	sprite30_.params.pos = Math::Vector2(386.0f, 100.0f); // 30秒のスプライトの位置を設定
	sprite30_.params.enableDrawRect(Rectf(
		0, 0, 512.0f, 512.0f
	));
	sprite10_.params.siz = Math::Vector2(512.0f, 512.0f); // 30秒のスプライトのサイズを設定
	sprite10_.params.pos = Math::Vector2(386.0f, 100.0f); // 30秒のスプライトの位置を設定
	sprite10_.params.enableDrawRect(Rectf(
		0, 0, 512.0f, 512.0f
	));



}

void BG::Update(float deltaTime)
{
	alltime_ .Update(deltaTime);
    float elapsed = alltime_.GetElapsedTime();
    if (!is30Visible_ && elapsed >= 30.0f) {
        is30Visible_ = true;
        sprite30_.SetHidden(false); // 30秒経過で表示
        // 必要ならアニメーション再生開始処理もここで
			// アニメーションの設定
		sprite30_.anim = Sprite::Anim();
		sprite30_.anim.repeatable = false;                       // ループするかしないか
		sprite30_.anim.drawRectAnim.frameRate = 35;              // アニメーションの速度
		sprite30_.anim.drawRectAnim.frameCount = 80;             // 画像にアニメーションが何コマあるか
		sprite30_.anim.drawRectAnim.horizontalFrameCount = 10;   // 横に並んでいるコマ数
    }
	if (!is10Visible_ && elapsed >= 50.0f) {
		is10Visible_ = true;
		sprite10_.SetHidden(false); // 30秒経過で表示
		// 必要ならアニメーション再生開始処理もここで
			// アニメーションの設定
		sprite10_.anim = Sprite::Anim();
		sprite10_.anim.repeatable = false;                       // ループするかしないか
		sprite10_.anim.drawRectAnim.frameRate = 45;              // アニメーションの速度
		sprite10_.anim.drawRectAnim.frameCount = 81;             // 画像にアニメーションが何コマあるか
		sprite10_.anim.drawRectAnim.horizontalFrameCount = 9;   // 横に並んでいるコマ数
	}

    // 既に表示中なら何もしない
}
