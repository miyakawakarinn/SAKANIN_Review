//MainScene.h
#pragma once

#include "../HuEngine.h"
#include "../Classes/BG.h"
#include "../Classes/Player.h"
#include "../Classes/Demofloor.h"
#include "../Classes/Breakfloor.h"
#include "../Classes/Enemy.h"
#include "../Classes/Obstacle.h"
#include "../Classes/Suiton.h"
#include "../Classes/SuitonMagic.h"
#include "../Classes/Katon.h"
#include "../Classes/Katonmagic.h"
#include "../Classes/KatonHusuma.h"
#include "../Classes/AllTime.h"
#include "Gameover.h"
#include "Resulttyunin.h"
#include "Resultjonin.h"
#include "Gameclear.h"



class MainScene : public HE::Scene
{
public:
	MainScene();
	virtual ~MainScene() { Terminate(); }

	void ResizeLayout() override;

	void Load() override;
	void Initialize() override;
	void Terminate() override;

	void Update(float deltaTime) override;

private:


	int Touch = 0;
	BG bg_;
	Player player_;
	Suiton suiton_;
	SuitonMagic suitonmagic_;
	Katon katon_;
	KatonMagic katonmagic_;
	KatonHusuma katonhusuma_[8]; // ふすま8枚分
	Demofloor demofloor_[15];
	Breakfloor breakfloor_[11];
	Enemy enemy_[2];//手裏剣は２個なので後々修正
	Obstacle obstacle_[12];
	Gameover gameover_;
	Resulttyunin resulttyunin_;
	Resultjonin resultjonin_;
	Gameclear gameclear_;
	AllTime alltime_;

	HE::Sound bgm_;
	HE::Sound se_damage_;
	//ポリモーフィズム使うと便利


	// 床の位置
	HE::Math::Vector2 demofloor_pos[15] =
    { HE::Math::Vector2(40.0f,0.0f), HE::Math::Vector2(540.0f,0.0f),HE::Math::Vector2(740.0f,0.0f),
	  HE::Math::Vector2(140.0f,175.0f),HE::Math::Vector2(340.0f,175.0f),HE::Math::Vector2(1040.0f,175.0f),
	  HE::Math::Vector2(40.0f,350.0f),HE::Math::Vector2(240.0f,350.0f),HE::Math::Vector2(740.0f,350.0f),
	  HE::Math::Vector2(140.0f,525.0f),HE::Math::Vector2(340.0f,525.0f),HE::Math::Vector2(1140.0f,525.0f),
	  HE::Math::Vector2(40.0f,700.0f), HE::Math::Vector2(540.0f,700.0f),HE::Math::Vector2(740.0f,700.0f)

	};
	//壊れる床の位置
	HE::Math::Vector2 breakfloor_pos[11] = { HE::Math::Vector2(440.0f,0.0f),HE::Math::Vector2(640.0f,0.0f),
	HE::Math::Vector2(40.0f,175.0f),HE::Math::Vector2(240.0f,175.0f),HE::Math::Vector2(940.0f,175.0f),
	HE::Math::Vector2(640.0f,350.0f),HE::Math::Vector2(240.0f,525.0f),HE::Math::Vector2(1040.0f,525.0f),
	HE::Math::Vector2(40.0f,525.0f),HE::Math::Vector2(440.0f,700.0f),HE::Math::Vector2(640.0f,700.0f),
	};
	// 床のサイズ	
	float floor_sizex[15] = { 
		400.0f,100.0f,400.0f,100.0f,600.0f,200.0f,100.0f,
		400.0f,400.0f,100.0f,700.0f,100.0f,400.0f,100.0f,400.0f,
	};
	// 壊れる床のサイズ
	float breakfloorsizex[11] = { 100.0f,100.0f,100.0f,100.0f,100.0f,
								  100.0f,100.0f,100.0f,100.0f,100.0f,100.0f
	};
	// 壊れるまでの時間
	float breakTime_[11] = {
	 15.0f,30.0f,15.0f,30.0f,15.0f,
	 15.0f,15.0f,15.0f,30.0f,15.0f,30.0f
	};
	//ふすまの位置
	HE::Math::Vector2 husuma_pos[8] = {
	{255.0f, -76.0f},{655.0f, -76.0f},{355.0f, 100.0f},{855.0f, 100.0f},
	{255.0f, 274.0f},{555.0f, 274.0f},{255.0f, 451.0f},{855.0f, 451.0f}
	};
	//	まきびしの高さのサイズは30.0f
	HE::Math::Vector2 obstacle_pos[12] = {
	{540.0f, 20.0f},{840.0f, 145.0f},{440.0f, 195.0f},{840.0f, 195.0f},
	{240.0f, 320.0f},{1040.0f, 320.0f},{340.0f, 360.0f},{740.0f, 360.0f},
		{540.0f, 495.0f},{940.0f, 495.0f},{840.0f, 555.0f},{540.0f, 670.0f}
	};

};