#include "pch.h"

#include "AvoApplication.h"
#include "AvoWindow.h"

namespace Avo
{
	void AvoApplication::Run()
	{
		Avo::AvoWindow::Init();
		Avo::AvoWindow::GetWindow()->CreateWindow(800, 600, "test");

		Initialize();

		while (ShouldContinue)
		{
			Update();
			
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