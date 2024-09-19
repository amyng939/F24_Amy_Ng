#include "AvoApplication.h"

namespace Avo
{
	void AvoApplication::Run()
	{
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