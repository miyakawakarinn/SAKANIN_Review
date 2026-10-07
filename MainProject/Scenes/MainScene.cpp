//
// MainScene.cpp
//

#include "MainScene.h"
#include "DontDestroyOnLoad.h"

using namespace HE;

// initialize member variables.
MainScene::MainScene()
{

}

// rearrange UI to fit the size.
void MainScene::ResizeLayout()
{
	Scene::ResizeLayout();



}

// load resources.
void MainScene::Load()
{

	bg_.Load();
	player_.Load();
	suiton_.Load(); //すいとんの術
	suitonmagic_.Load(); //すいとんの術
	katon_.Load(); //火遁の術
	katonmagic_.Load(); //火遁の術
	enemy_[0].Load();
	enemy_[1].Load();//手裏剣の読み込み
	for (int i = 0; i < 12; i++) {
		obstacle_[i].Load();
	}//まきびしの読み込み
	for (int i = 0; i < 15; i++) {
		demofloor_[i].Load();
	}//床の読み込み
	for (int i = 0; i < 11; i++) {
		breakfloor_[i].Load();
	}//壊れる床の読み込み
	for (int i = 0; i < 8; ++i) {
        katonhusuma_[i].Load();
    }// ふすまの読み込み

	bgm_ = Sound("bgm_main.wav", Sound::LoopCount::BGM);
	bgm_.Play();
	se_damage_ = Sound("se_player_damage.wav", Sound::LoopCount::SE);
	Scene::Load();
}

// initialize a variables.
void MainScene::Initialize()
{
	bg_.Initialize();
	player_.Initialize();
	suiton_.Initialize(); //すいとんの術
	suitonmagic_.Initialize(); //すいとんの術
	katon_.Initialize(); //火遁の術
	katonmagic_.Initialize(); //火遁の術
	enemy_[0].Initialize(Math::Vector2(940, 355));
	enemy_[1].Initialize(Math::Vector2(390, 530));
	for (int i = 0; i < 12; ++i) {
		obstacle_[i].Initialize(obstacle_pos[i]);
	}//まきびしのinitialize
	for (int i = 0; i < 15; ++i) {
		demofloor_[i].Initialize(demofloor_pos[i], floor_sizex[i]);
	}
	for (int i = 0; i < 11; ++i) {//壊れる床
		breakfloor_[i].Initialize(breakfloor_pos[i],breakTime_[i], breakfloorsizex[i]); 
	}
	for (int i = 0; i < 8; ++i) {//ふすま
        katonhusuma_[i].Initialize();
        katonhusuma_[i].SetPosition(husuma_pos[i]); // 位置を設定
    }

}
// releasing resources required for termination.
void MainScene::Terminate()
{

}

// updates the scene.
void MainScene::Update(float deltaTime)
{

	bg_.Update(deltaTime);
	suiton_.Update(deltaTime); //すいとんの術
	suitonmagic_.Update(deltaTime);
	suitonmagic_.SetPosition(suiton_.GetPosition());
	katon_.Update(deltaTime); //火遁の術
	katonmagic_.SetPosition(katon_.GetPosition());
	katonmagic_.Update(deltaTime);
	alltime_.Update(deltaTime);
	float elapsed = alltime_.GetElapsedTime();
	DontDestroy.elapsedTime_ = elapsed; //経過時間をDontDestroyOnLoadに保存
	for (int i = 0; i < 11; ++i) {
		breakfloor_[i].Update(deltaTime);
	}


	// 衝突判定
	Math::Rectangle player_collision = player_.GetCollision();
	Math::Rectangle enemy1_collision = enemy_[0].GetCollision();//敵のコリジョン
	Math::Rectangle enemy2_collision = enemy_[1].GetCollision();
	Math::Rectangle suiton_collision = suitonmagic_.GetCollision();//すいとんの術のコリジョン
	Math::Rectangle katon_collision = katonmagic_.GetCollision();//火遁の術のコリジョン
	//まきびしのコリジョン
	Math::Rectangle obstacle1_collision = obstacle_[0].GetCollision();
	Math::Rectangle obstacle2_collision = obstacle_[1].GetCollision();
	Math::Rectangle obstacle3_collision = obstacle_[2].GetCollision();
	Math::Rectangle obstacle4_collision = obstacle_[3].GetCollision();
	Math::Rectangle obstacle5_collision = obstacle_[4].GetCollision();
	Math::Rectangle obstacle6_collision = obstacle_[5].GetCollision();
	Math::Rectangle obstacle7_collision = obstacle_[6].GetCollision();
	Math::Rectangle obstacle8_collision = obstacle_[7].GetCollision();
	Math::Rectangle obstacle9_collision = obstacle_[8].GetCollision();
	Math::Rectangle obstacle10_collision = obstacle_[9].GetCollision();
	Math::Rectangle obstacle11_collision = obstacle_[10].GetCollision();
	Math::Rectangle obstacle12_collision = obstacle_[11].GetCollision();

	//下忍
	if (elapsed <= 20.0f) {
		//プレイヤーが手裏剣に接触した場合
		if (player_collision.Intersects(enemy1_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Gameover);
		}
		if (player_collision.Intersects(enemy2_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Gameover);
		}
		//まきびしに当たった場合
		if (player_collision.Intersects(obstacle1_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Gameover);
		}
		if (player_collision.Intersects(obstacle2_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Gameover);
		}
		if (player_collision.Intersects(obstacle3_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Gameover);
		}
		if (player_collision.Intersects(obstacle4_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Gameover);
		}
		if (player_collision.Intersects(obstacle5_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Gameover);
		}
		if (player_collision.Intersects(obstacle6_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Gameover);
		}
		if (player_collision.Intersects(obstacle7_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Gameover);
		}
		if (player_collision.Intersects(obstacle8_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Gameover);
		}
		if (player_collision.Intersects(obstacle9_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Gameover);
		}
		if (player_collision.Intersects(obstacle10_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Gameover);
		}
		if (player_collision.Intersects(obstacle11_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Gameover);
		}
		if (player_collision.Intersects(obstacle12_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Gameover);
		}
		//すいとんの術に当たった場合
		if (player_collision.Intersects(suiton_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Gameover);
		}
		//火遁の術に当たった場合
		if (player_collision.Intersects(katon_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Gameover);
		}
	}
	//中忍
	if (elapsed >= 20.0f && elapsed <= 40.0f) {
		//プレイヤーが手裏剣に接触した場合
		if (player_collision.Intersects(enemy1_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Resulttyunin);
		}
		if (player_collision.Intersects(enemy2_collision)) {
			SceneManager.SetNextScene(NextScene::Resulttyunin);
		}
		//まきびしに当たった場合
		if (player_collision.Intersects(obstacle1_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Resulttyunin);
		}
		if (player_collision.Intersects(obstacle2_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Resulttyunin);
		}
		if (player_collision.Intersects(obstacle3_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Resulttyunin);
		}
		if (player_collision.Intersects(obstacle4_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Resulttyunin);
		}
		if (player_collision.Intersects(obstacle5_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Resulttyunin);
		}
		if (player_collision.Intersects(obstacle6_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Resulttyunin);
		}
		if (player_collision.Intersects(obstacle7_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Resulttyunin);
		}
		if (player_collision.Intersects(obstacle8_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Resulttyunin);
		}
		if (player_collision.Intersects(obstacle9_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Resulttyunin);
		}
		if (player_collision.Intersects(obstacle10_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Resulttyunin);
		}
		if (player_collision.Intersects(obstacle11_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Resulttyunin);
		}
		if (player_collision.Intersects(obstacle12_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Resulttyunin);
		}
		//すいとんの術に当たった場合
		if (player_collision.Intersects(suiton_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Resulttyunin);
		}
		//火遁の術に当たった場合
		if (player_collision.Intersects(katon_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Resulttyunin);
		}
	}
	//上忍
	if (elapsed >= 40.0f && elapsed < 60.0f) {
		//プレイヤーが手裏剣に接触した場合
		if (player_collision.Intersects(enemy1_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Resultjonin);//敵に当たったらゲームオーバー
		}
		if (player_collision.Intersects(enemy2_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Resultjonin);
		}
		//まきびしに当たった場合
		if (player_collision.Intersects(obstacle1_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Resultjonin);//敵に当たったらゲームオーバー
		}
		if (player_collision.Intersects(obstacle2_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Resultjonin);
		}
		if (player_collision.Intersects(obstacle3_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Resultjonin);
		}
		if (player_collision.Intersects(obstacle4_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Resultjonin);
		}
		if (player_collision.Intersects(obstacle5_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Resultjonin);
		}
		if (player_collision.Intersects(obstacle6_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Resultjonin);
		}
		if (player_collision.Intersects(obstacle7_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Resultjonin);
		}
		if (player_collision.Intersects(obstacle8_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Resultjonin);
		}
		if (player_collision.Intersects(obstacle9_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Resultjonin);
		}
		if (player_collision.Intersects(obstacle10_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Resultjonin);
		}
		if (player_collision.Intersects(obstacle11_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Resultjonin);
		}
		if (player_collision.Intersects(obstacle12_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Resultjonin);
		}
		//すいとんの術に当たった場合
		if (player_collision.Intersects(suiton_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Resultjonin);//敵に当たったらゲームオーバー
		}
		//火遁の術に当たった場合
		if (player_collision.Intersects(katon_collision)) {
			se_damage_.PlayFromTop();
			SceneManager.SetNextScene(NextScene::Resultjonin);//敵に当たったらゲームオーバー
		}
	}


	// ① 物理更新：移動・重力など
	std::vector<Demofloor> floors(std::begin(demofloor_), std::end(demofloor_));
	player_.Update(floors);

	// ② 衝突判定：重力方向でフロア or シーリングを呼び分ける
	int touch = 0;
	auto playerCol = player_.GetCollision();
	//ここから床のコリジョン
	for (int i = 0; i < 15; ++i) {//ここで床の数の変更
		if (playerCol.Intersects(demofloor_[i].GetCollision())) {
			player_.OnCollisionGround(demofloor_[i].GetFloorPositionY());
			++touch;
			break;
		}
	}//ここまで床のコリジョン
	//ここから壊れる床のコリジョン
	for (int i = 0; i < 11; ++i) {//ここで床の数の変更
		if (playerCol.Intersects(breakfloor_[i].GetCollision())) {
			player_.OnCollisionGround(breakfloor_[i].GetFloorPositionY());
			++touch;
			break;
		}
	}

	if (touch == 0) {
		player_.OutCollisionGround();
	}


	enemy_[0].Update((350.0f), (940.0f));//大きい数値＞小さい数値でかいてるよ
	enemy_[1].Update((390.0f), (525.0f));
	obstacle_[0].Update(Math::Vector2());
	obstacle_[1].Update(Math::Vector2());
	obstacle_[2].Update(Math::Vector2());
	obstacle_[3].Update(Math::Vector2());


	if (elapsed >= 60.0f) {//ここで制限時間を変更
		SceneManager.SetNextScene(NextScene::Gameclear);
		return;
	}

	// ふすまの更新
	for (int i = 0; i < 7; ++i) {
		katonhusuma_[i].Update(deltaTime);
	}
	Scene::Update(deltaTime);
	
}
