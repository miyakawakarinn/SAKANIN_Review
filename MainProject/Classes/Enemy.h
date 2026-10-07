//Enemy.h
#pragma once

#include "../HuEngine.h"


class Enemy {
public:
    void Load();
    void Initialize(HE::Math::Vector2 Initialposition);
    void Update(float minX, float maxX);
    void OnCollision();
    HE::Math::Rectangle GetCollision();
    HE::Math::Vector3 GetPosition() const { return sprite_.params.pos; }

private:
    HE::Sprite sprite_;

    float Inversion;
    float minX_ = 0.0f;  // Åö ç∂í[
    float maxX_ = 0.0f;  // Åö âEí[

};