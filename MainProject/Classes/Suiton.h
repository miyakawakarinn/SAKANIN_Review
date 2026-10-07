#pragma once

#include "../HuEngine.h"
#include "../Classes/AllTime.h"


class Suiton {
public:

	
	void Load();
	void Initialize();
	void Update(float deltaTime);
	void RandomPos(int randomNum);
	HE::Math::Vector3 GetPosition() { return magicsprite_.params.pos; }
private:

	HE::Sprite sprite_;
	HE::Sprite magicsprite_; // 当たり判定予告のスプライト

	bool isSprite_ = false; // 30秒のスプライトの表示状態

	AllTime alltime_; // AllTimeのインスタンスを追加
};