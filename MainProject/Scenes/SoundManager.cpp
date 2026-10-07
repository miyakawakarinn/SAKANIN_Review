//#include "SoundManager.h"
//#include <iostream> // デバッグ用
//
//void SoundManager::PlaySE(const std::string& filename)
//{
//    // ここでサウンドAPIを使って効果音を再生する
//    // 例: YourSoundAPI::Play(filename);
//    std::cout << "[SE] Play: " << filename << std::endl;
//
//    // ダミー管理
//    auto se = std::make_unique<PlayingSE>();
//    se->isPlaying = true;
//    se->filename = filename;
//    playingSE_.push_back(std::move(se));
//}
//
//void SoundManager::PlayBGM(const std::string& filename)
//{
//    // ここでサウンドAPIを使ってBGMを再生する
//    // 例: YourSoundAPI::PlayBGM(filename);
//    std::cout << "[BGM] Play: " << filename << std::endl;
//
//    bgmPlaying_ = true;
//    bgmFilename_ = filename;
//    // bgmInstance_ = ...;
//}
//
//void SoundManager::StopBGM()
//{
//    // ここでサウンドAPIを使ってBGMを停止する
//    // 例: YourSoundAPI::StopBGM();
//    std::cout << "[BGM] Stop" << std::endl;
//
//    bgmPlaying_ = false;
//    // bgmInstance_ = nullptr;
//}
//
//void SoundManager::Update()
//{
//    // ここでサウンドAPIから再生状態を取得し、playingSE_から終了したSEを削除する
//    // ダミー: 全て再生終了とみなしてクリア
//    playingSE_.clear();
//}