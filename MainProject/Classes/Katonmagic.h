#pragma once

#include "../HuEngine.h"
#include "../Classes/AllTime.h"


class KatonMagic {
public:


	void Load();
	void Initialize();
	void Update(float deltaTime);
	void OnCollision();
	HE::Math::Rectangle GetCollision();
	void SetPosition(const HE::Math::Vector3& pos) {
		areasprite_.params.pos = pos;
	}
private:

	HE::Sprite areasprite_;
	HE::Sound se_;
	
	bool isSprite_ = false; // 30秒のスプライトの表示状態

	AllTime alltime_; // AllTimeのインスタンスを追加
};