/*=========================================
	Copyright 2024-2025 Norbert Gerberg
=========================================*/
#ifndef AUDIOSRC_HPP
#define AUDIOSRC_HPP
#include "Types.hpp"
#include "soloud/soloud.h"
#include "soloud/soloud_wav.h"

typedef SoLoud::handle		eAudioHandle;
typedef SoLoud::AudioSource eAudioOG;
typedef SoLoud::Wav			eAudioWav;
typedef SoLoud::Soloud		eAudioCore;
typedef SoLoud::result		eAudioErr;

struct eAudioSrc
{
	eAudioWav		mSource;
	eAudioHandle	mHandle;
};
#endif