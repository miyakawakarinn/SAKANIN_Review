//Player.cpp
#include "Player.h"
#include "Demofloor.h"

using namespace HE;

void Player::OnCollisionGround(float floorposY_)
{
    // 床の上にキャラの左上を合わせる
    if (isGravityUpward) {
        player_position_.y = floorposY_ + 19.0f;
    }
    else {
        player_position_.y = floorposY_ - spriteplayer_.params.siz.y + 1;
    }
    gravityDir = 0;
    velocityY = 0.0f;
    isOnGround = true; // 床に着地した状態にする
}

void Player::OutCollisionGround()
{
    gravityDir = isGravityUpward ? -1 : 1;
    isOnGround = false;
}

Math::Rectangle Player::GetCollision()
{
    Math::Rectangle collision;
    collision.x = (long)player_position_.x;
    collision.y = (long)player_position_.y;
    collision.width = (long)spriteplayer_.params.siz.x;
    collision.height = (long)spriteplayer_.params.siz.y;

    return collision;
}

void Player::Load()
{
    spriteplayer_ = Sprite("player_sprite_sheet.png");//左向き
    RenderingPath->AddSprite(&spriteplayer_, 0);

	se_jump_ = Sound("se_player_gravity.wav", Sound::LoopCount::SE); // ジャンプ音の読み込み

}

void Player::Initialize()
{
    spriteplayer_.params.siz = Math::Vector2(60.0f, 60.0f);
    player_position_ = Math::Vector2(100.0f, 0.0f);//560.0f, 290.0f
    spriteplayer_.params.enableDrawRect(Rectf(
        0, 0, 100.0f, 100.0f
    ));
    direction = 1;
    isGravityUpward = false;
    gravityDir = 1;
    isOnGround = false;

    // アニメーションの設定
    spriteplayer_.anim = Sprite::Anim();
    spriteplayer_.anim.repeatable = true;                       // ループするかしないか
    spriteplayer_.anim.drawRectAnim.frameRate = 15;              // アニメーションの速度
    spriteplayer_.anim.drawRectAnim.frameCount = 6;             // 画像にアニメーションが何コマあるか
    spriteplayer_.anim.drawRectAnim.horizontalFrameCount = 6;   // 横に並んでいるコマ数
}

void Player::InvertGravity() {
    if (isOnGround && InputSystem.Keyboard.wasPressedThisFrame.Space) {
        isGravityUpward = !isGravityUpward;
        gravityDir = isGravityUpward ? -1 : 1;
        isOnGround = false;
		se_jump_.Stop();
        se_jump_.Play();

    }
}

void Player::Update(const std::vector<Demofloor>& floors) {
    InvertGravity();

    if (isOnGround) {
        player_position_.x += direction * 400.0f * Time.deltaTime;
    }
    else {
        player_position_.y += gravityDir * 100.0f * (++velocityY) * Time.deltaTime;
    }
    // 最大位置に達した場合の処理、横
    if (player_position_.x > 1180.0f) {
        spriteplayer_.params.enableMirror();
        direction = -1; // 反転
    }
    else if (player_position_.x < 40.0f) {
        spriteplayer_.params.disableMirror();
        direction = 1; // 反転
    }

    //最大位置に達した場合の処理、縦
    if (player_position_.y < -100.0f)//上に言ったら下に行く
        player_position_.y = 820.0f;

    if (player_position_.y > 820.0f)//下に行ったら上に行く
        player_position_.y = -100.0f;

	spriteplayer_.params.pos = player_position_;

    if (isGravityUpward) {
        spriteplayer_.params.scale.y = -1.0;
        spriteplayer_.params.pos.y = player_position_.y + 60.0f;
    }
    else
    {
        spriteplayer_.params.scale.y = 1.0;
        spriteplayer_.params.pos.y = player_position_.y;
    }



}