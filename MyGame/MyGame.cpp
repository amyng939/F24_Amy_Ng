#include"Avo.h"
#include<iostream>

class MyGameApplication : public Avo::AvoApplication
{
	virtual void Initialize() override
	{
		AVO_ERROR("Starting...");

		Avo::AvoWindow win;
		win.CreateWindow(800, 600, "test");
	}

	virtual void Update() override
	{
		//std::cout << "Running" << std::endl;
	}
};

AVO_GAME_START(MyGameApplication)