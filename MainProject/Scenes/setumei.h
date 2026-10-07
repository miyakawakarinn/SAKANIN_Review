
#pragma once

#include "../HuEngine.h"

class setumei : public HE::Scene
{
public:
    setumei();
    virtual ~setumei() { Terminate(); }

    void ResizeLayout() override;

    void Load() override;
    void Initialize() override;
    void Terminate() override;

    void Update(float deltaTime) override;

private:
    HE::Sprite sprite_;


};