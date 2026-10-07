
#pragma once

#include "../HuEngine.h"
#include "setumei.h"


class Title : public HE::Scene
{
public:
    Title();
    virtual ~Title() { Terminate(); }

    void ResizeLayout() override;

    void Load() override;
    void Initialize() override;
    void Terminate() override;

    void Update(float deltaTime) override;

private:
	HE::Sprite sprite_;
	HE::Sprite button1_;
	HE::Sprite select_;

	HE::Sound se_start_;
	HE::Sound se_setumei_;
	HE::Sound se_select_;

	HE::Sound bgm_;

	float selectnum_ = 0; // 選択中のボタンの位置


};