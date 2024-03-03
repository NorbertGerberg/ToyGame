/*=========================================
	Copyright 2024-2025 Norbert Gerberg
=========================================*/
#include "GameRenderer.hpp"
#include "GameTask.hpp"

bool GameTask::Initialize()
{
	if (!SuperInit())
		return false;

	uint32 width	= 1280;
	uint32 height	= 720;

	//Create window
	mWnd->SetSize(vec2i(width, height));
	mWnd->SetTitle("ToyGame Project");
	mWnd->Initialize();
	mWnd->SetWindowVisibility(false);
	mWnd->CenterWindow();

	//Init renderer
	mRenderer = new GameRenderer(mWnd, width, height, true, 16, eRenderAPI::Direct3D11);

	mWnd->SetWindowVisibility(true);

	mQuit		= false;
	mGameSpeed	= 1.0f;
	mTime->SetSpeed(&mGameSpeed);

	return true;
}

void GameTask::Update()
{
	mTime->Update();
	mQuit = mWnd->WindowCloseRequested();
}

void GameTask::Render()
{
	if (!mWnd->IsWindowIconified())
	{
		mRenderer->PreUpdate(true, 16);

		eDI::Begin("Demo Window", nullptr, ImGuiWindowFlags_NoSavedSettings);
		eDI::Text("Hello, ToyGame!");
		eDI::End();

		mRenderer->Update();
	}
}

void GameTask::Unload()
{
	if (mRenderer != nullptr)
	{
		mRenderer->SetWindow(nullptr);
		delete mRenderer;
	}

	mTime->SetSpeed(nullptr);

	SuperUnload();
}