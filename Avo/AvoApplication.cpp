#include "pch.h"

#include "AvoApplication.h"
#include "AvoWindow.h"
#include "Image.h"
#include "Shaders.h"
#include "Renderer.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"

#include "stb_image.h"

namespace Avo
{
	void AvoApplication::Run()
	{
		Avo::AvoWindow::Init();
		Avo::AvoWindow::GetWindow()->CreateWindow(800, 600, "test");

		Renderer::Init();

		Initialize();

		Avo::Image pic{ "../Avo/AvoAssets/Images/Slowpoke.png" };
		int x{ 100 };

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		while (mShouldContinue)
		{
			Update();

			Renderer::ClearScreen();
				
			Renderer::Draw(pic, x, 100);
			x += 2;

			std::this_thread::sleep_until(mNextFrameTime);			
			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
			
			Avo::AvoWindow::GetWindow()->SwapBuffers();
			Avo::AvoWindow::GetWindow()->PollEvents();
		}

		Shutdown();
	}


	void AvoApplication::Initialize()
	{

	}


	void AvoApplication::Update()
	{

	}


	void AvoApplication::Shutdown()
	{
	}

}


/*

Avo::Image pic("Assets/image1.png");
Avo::Renderer::Get()->Draw(pic, 100,200);


*/