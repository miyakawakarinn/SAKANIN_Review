//Player.h
#pragma once

#include "../HuEngine.h"
#include "Demofloor.h"
class Demofloor;

class Player {
public:
	void Load();
	void Initialize();
	//void Update(/*Demofloor demofloor_[]*/);
	void Update(const std::vector<Demofloor>& floors);

	HE::Math::Rectangle GetCollision();
	void OnCollisionGround(float floorposY_);
	void OutCollisionGround();

	void StopVerticalMovement() {
		gravityDir = 0;          // 重力方向をゼロに
		// fallingspeed = 0;       // 落下（上昇）速度をゼロに
	}

	/// 重力方向（1：下向き／-1：上向き）
	int gravityDir = 1;
	/// 垂直方向の速度（落下／上昇速度）
	float velocityY = 0.0f;
	/// 重力加速度の大きさ
	static constexpr float gravityAccel = 16000.0f;

	/// 重力を反転させる
	void InvertGravity();

	// 重力方向を返す。下向きなら1、上向きなら-1など
	int GetGravityDir() const { return gravityDir; }


private:
	HE::Sprite spriteplayer_;

	HE::Sound se_jump_;

	float chara_speed = spriteplayer_.params.pos.x += 300.0f;
	float direction;//移動反転
	float gravity;//重力
	float fallingspeed;//重力
	int flg_ = 0;
	//ジャンプ用
	int jump_flug_;               // フラグ
	float jump_power_;            // 現在のジャンプ力

	//重力の反転、地面から離れる
	bool isOnGround;
	bool isGravityUpward;

	float SpaceButton = 0;
	HE::Math::Vector2 player_position_; // プレイヤーの位置
	//プレイヤーポジションという変数をヘッダーで作ってゲーム上の画像の処理は全てここで行う
};