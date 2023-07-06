#include <Novice.h>
#include"map.h"
#include"Player.h"
#include"SoundSource.h"
const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
	WinApp* winApp=nullptr;
	winApp->GetInstance();
	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};
	const int kMaxIndexX = 20;
	const int kMaxIndexY = 12;
	MyXAudio2* XAudio2 = new MyXAudio2();
	XAudio2->Initialize();
	Map* map = new Map;
	map->Initialize();
	Player* player = new Player();
	player->Initialize({ 64,64 });
	SoundSource* soundSource = new SoundSource();
	soundSource->Initialize({ 128,128 });
	soundSource->SetMap(map);
	soundSource->SetPlayer(player);
	//int fanfare = XAudio2->LoadAudio(L"./Resources/fanfare.wav");
	int mokugyo = XAudio2->LoadAudio(L"./Resources/mokugyo.wav");
	int mokugyo2 = XAudio2->LoadAudio(L"./Resources/mokugyo.wav");
	Vector2 Volume = {0,0};
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		//XAudio2->Play(fanfare);
		Volume = { 0,0 };
		player->Update(keys);
		soundSource->Move(keys);
		soundSource->Update();

		Volume.y = 0.05f * (20.0f - (float)soundSource->SoundScore[Right]);
		if (Volume.y < 0.0f) {
			Volume.y = 0.0f;
		}else if (Volume.y > 1) {
			Volume.y = 1;
		}
		XAudio2->Play(mokugyo, Volume.y,-1);
		Volume.x = 0.05f * (20.0f - (float)soundSource->SoundScore[Left]);
		if (Volume.x <= 0.0f) {
			Volume.x = 0.0f;
		}
		else if (Volume.x > 1) {
			Volume.x = 1;
		}
		XAudio2->Play(mokugyo2, Volume.x,1);
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		map->Draw();
		soundSource->Draw();
		player->Draw();
		Novice::ScreenPrintf(900, 20, "Right = %d", soundSource->SoundScore[Right]);
		Novice::ScreenPrintf(900, 35, "Left = %d", soundSource->SoundScore[Left]);
		Novice::ScreenPrintf(700, 20, "RightVolume = %f", Volume.y);
		Novice::ScreenPrintf(700, 35, "LeftVolume = %f", Volume.x);
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	XAudio2->Release();
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
