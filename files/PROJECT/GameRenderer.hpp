/*=========================================
	Copyright 2024-2025 Norbert Gerberg
=========================================*/
#ifndef GAMERENDERER_HPP
#define GAMERENDERER_HPP
#include <ToyGame/Types.hpp>
#include <ToyGame/String.hpp>
#include <ToyGame/Renderer.hpp>

class GameRenderer : public eRenderer
{
public:
	GameRenderer(eWindow* window, uint32 width, uint32 height, bool vsync, uint8 msaa, eRenderAPI api);
	~GameRenderer();
	void PreUpdate(bool vsync, uint8 msaa);
	void Update();

	void SetWindow(eWindow* window);
	eWindow* GetWindow();

private:
	eWindow*	mWnd;
	eLayer*		m2DPass;
};
#endif