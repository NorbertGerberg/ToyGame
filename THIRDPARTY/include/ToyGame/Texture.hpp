/*=========================================
	Copyright 2024-2025 Norbert Gerberg
=========================================*/
#ifndef TEXTURE_HPP
#define TEXTURE_HPP
#include "Types.hpp"
#include "String.hpp"
#include "Quality.hpp"
#include <bgfx/bgfx.h>

typedef bgfx::TextureInfo			eTextureInfo;
typedef bgfx::TextureFormat::Enum	eTextureFormat;
typedef bgfx::TextureHandle			eTextureHandle;

class eTexture;

struct eTextureAtlas
{
	vec2 mSize = vec2(352.0f);
	vec2 mSubSize = vec2(32.0f);
	eTexture* mTexture = nullptr;
};

struct eTextureData
{
	unsigned char*  mData;
	eString			mName;
	vec2i			mSize;
	int				mNbComponents;
};

class eTexture
{
public:
	eTexture(bool autoDestroy = true);
	~eTexture();
	void Release();
	void Load(eString filename, const bool flipUV = true, uint64 flags = BGFX_TEXTURE_NONE | BGFX_SAMPLER_NONE);
	void LoadMem(eTextureData& data, uint64 flags = BGFX_TEXTURE_NONE | BGFX_SAMPLER_NONE);
	void SetHandle(eTextureHandle handle);
	eTextureHandle GetHandle();
	vec2i GetSize();

	static eQuality* mQuality;

	bool mSolidQuality;

private:
	eTextureHandle	mHandle = BGFX_INVALID_HANDLE;
	bool			mAutoDestroy;
	vec2i			mSize;
};
#endif