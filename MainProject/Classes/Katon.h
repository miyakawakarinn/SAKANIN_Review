#pragma once

#include "../HuEngine.h"
#include"Katonmagic.h"
#include "KatonHusuma.h"
#include "../Classes/AllTime.h"


class Katon {
public:
	HE::Sprite sprite_;
	HE::Sprite magicsprite_; //当たり判定予告のスプライト

	void Load();
	void Initialize();
	void Update(float deltaTime);
	void RandomPos(int randomNum);
	HE::Math::Vector3 GetPosition() { return magicsprite_.params.pos; }

    void SetSpriteHidden(bool hidden) { sprite_.SetHidden(hidden); }
    void SetMagicspriteHidden(bool hidden) { magicsprite_.SetHidden(hidden); }
    void SetSpritePosition(const HE::Math::Vector2& pos) { sprite_.params.pos = pos; }
    void SetMagicspritePosition(const HE::Math::Vector2& pos) { magicsprite_.params.pos = pos; }
private:

	bool isSprite_ = false; // 忍者の表示状態

	AllTime alltime_; // AllTimeのインスタンスを追加
};