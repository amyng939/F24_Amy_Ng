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