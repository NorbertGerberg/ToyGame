/*=========================================
	Copyright 2024-2025 Norbert Gerberg
=========================================*/
#ifndef GAMETASK_HPP
#define GAMETASK_HPP
#include <ToyGame/Types.hpp>
#include <ToyGame/String.hpp>
#include <ToyGame/Task.hpp>

class GameRenderer;

class GameTask : public eTask
{
public:
	bool Initialize();
	void Update();
	void Render();
	void Unload();

	bool			mQuit;

private:
	real3			mGameSpeed;
	GameRenderer*	mRenderer;
};
#endif