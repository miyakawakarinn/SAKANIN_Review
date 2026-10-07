//Demofloor.h
#pragma once

#include "../HuEngine.h"
#include "Player.h"

class Demofloor {
public:
    void Load();
    void Initialize(HE::Math::Vector2 Initialposition,float floorsizex);
    void Update();
    void OnCollision();

    //  void SetPlayer(Player* p) { playerPtr_ = p; }

    HE::Math::Rectangle GetCollision();
    float GetFloorPositionX() const { return spritefloor_.params.pos.x; }// 床の位置を取得するための機能
    float GetFloorPositionY() const { return spritefloor_.params.pos.y; }
    float GetHeight() const { return spritefloor_.params.siz.y; }

    // 床の位置（x,y）をまとめて取得する
    HE::Math::Vector2 GetPosition() const;


private:
    HE::Sprite spritefloor_;
    //   HE::Math::Vector3 GetPosition() const { return spritefloor_.params.pos; }

       //Player* playerPtr_ = nullptr;
};