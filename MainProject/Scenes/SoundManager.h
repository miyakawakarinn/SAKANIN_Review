//#pragma once
//#include <vector>
//#include <string>
//#include <memory>
//
//// サウンドAPIのヘッダをここでインクルード
//// #include <YourSoundAPI.h>
//
//class SoundManager
//{
//public:
//    void PlaySE(const std::string& filename);
//    void PlayBGM(const std::string& filename);
//    void StopBGM();
//    void Update();
//
//private:
//    // サウンドAPIのハンドルやインスタンスを直接管理
//    struct PlayingSE {
//        // 例: サウンドAPIのインスタンス
//        // YourSoundAPI::Instance* instance;
//        bool isPlaying;
//        std::string filename;
//    };
//    std::vector<std::unique_ptr<PlayingSE>> playingSE_;
//    // BGM用のインスタンス
//    // YourSoundAPI::Instance* bgmInstance_;
//    bool bgmPlaying_ = false;
//    std::string bgmFilename_;
//};