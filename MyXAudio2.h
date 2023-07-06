#pragma once
#include "DirectXCommon.h"
#include <mmsystem.h>
#include <xaudio2.h>
#include<x3daudio.h>
#include"Vector2.h"
#include<cassert>
#pragma comment(lib, "winmm.lib")
#pragma comment(lib,"xaudio2.lib")

class MyXAudio2 {
public:

	void Initialize();
	int LoadAudio(const wchar_t* filePath);
	void Release();
	void Play(int AudioInDex, float AudioVolume, int pan);

private:
	float left = 0;
	float right = 0;
	static const int kMaxAudio = 8;
	HRESULT hr;
	IXAudio2* XAudioInterface=nullptr;
	IXAudio2MasteringVoice* pMasteringVoice = nullptr;
	IXAudio2SourceVoice* pSourceVoice[kMaxAudio];
	bool IsusedAudioIndex[kMaxAudio];
	float outputMatrix[8];
	void Log(const std::string& message);
};

