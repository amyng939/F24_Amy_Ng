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
	AvoApplication::AvoApplication()
	{
		Avo::AvoWindow::Init();
		Avo::AvoWindow::GetWindow()->CreateWindow(1920, 1080, "test");

		Renderer::Init();

		SetWindowEventHandler(
			[this](const WindowEvent& event) {DefaultWindowEventHandler(event); });

	}

	void AvoApplication::Run()
	{
		Initialize();

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		while (mShouldContinue)
		{
			Renderer::ClearScreen();

			Update();
				
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
		mShouldContinue = false;
	}


	void AvoApplication::SetKeyEventHandler(const std::function<void(const KeyEvent&)>& newHandler)
	{
		Avo::AvoWindow::GetWindow()->SetKeyEventHandler(newHandler);
	}

	void AvoApplication::SetWindowEventHandler(std::function<void(const WindowEvent&)> newHandler)
	{
		Avo::AvoWindow::GetWindow()->SetWindowEventHandler(newHandler);
	}

	void AvoApplication::DefaultWindowEventHandler(const WindowEvent& event)
	{
		if (event.GetWindowAction() == WindowEvent::WindowAction::Close)
			mShouldContinue = false;
	}

}