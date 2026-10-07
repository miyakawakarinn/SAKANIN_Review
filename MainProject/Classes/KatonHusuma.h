#pragma once

#include "../HuEngine.h"
#include "../Classes/AllTime.h"


class KatonHusuma {
public:


	void Load();
	void Initialize();
	void Update(float deltaTime);

	HE::Sprite sprite_; 
	HE::Sprite room_[8];

    void SetPosition(const HE::Math::Vector2& pos) { sprite_.params.pos = pos; }
private:

	AllTime alltime_; 
	bool isPlaying = false; // ふすまのアニメーションが再生中かどうか

	HE::Sound se_;
};