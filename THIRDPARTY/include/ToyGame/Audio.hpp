/*=========================================
	Copyright 2024-2025 Norbert Gerberg
=========================================*/
#ifndef AUDIO_HPP
#define AUDIO_HPP
#include "Types.hpp"
#include "String.hpp"
#include "soloud/soloud.h"
#include "soloud/soloud_wav.h"
#include "soloud/soloud_openmpt.h"
#include "AudioSrc.hpp"

class eAudio
{
public:
	~eAudio();
	bool Initialize();
	void Unload();

	eAudioCore* GetCore();
	void Seek(eAudioHandle handle, real6 seconds);
	void FadeSwitch(eAudioSrc& begin, eAudioSrc& last, real6 fadeOutTimeSeconds = 2.0, real6 fadeInTimeSeconds = 1.5, real3 endVolume = 1.0f);
	void CancelFade(eAudioHandle handle);

	void LoadFile(eAudioSrc& obj, eString filepath);
	void LoadMem(eAudioSrc& obj, eString file);

private:
	eAudioCore* mSoloud;
};
#endif