
#pragma once

#include "../HuEngine.h"

class Resulttyunin : public HE::Scene
{
public:
      Resulttyunin();
    virtual ~Resulttyunin() { Terminate(); }

    void ResizeLayout() override;

    void Load() override;
    void Initialize() override;
    void Terminate() override;

    void Update(float deltaTime) override;

private:
    HE::Sprite sprite_;
    HE::Sprite select_;
    HE::Sprite bg_;

    HE::SpriteFont result_time_;
    HE::Sound se_select_;
	HE::Sound bgm_;

    float selectnum_ = 0; // 選択中のボタンの位置
};