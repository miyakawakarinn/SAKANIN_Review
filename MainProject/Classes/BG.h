#pragma once

#include "../HuEngine.h"
#include "../Classes/AllTime.h"

class BG {
public:

	void Load();
	void Initialize();
	void Update(float deltaTime);
private:
	
	HE::Sprite sprite_;
	HE::Sprite spritewall1_; // 壁のスプライト
	HE::Sprite spritewall2_; // 2つ目の壁のスプライト（必要なら追加）
	HE::Sprite sprite30_; // 30秒のスプライト（必要なら追加）
	HE::Sprite sprite10_;
	bool is30Visible_ = false; // 30秒のスプライトの表示状態
	bool is10Visible_ = false; // 10秒のスプライトの表示状態

	AllTime alltime_; // AllTimeのインスタンスを追加
};