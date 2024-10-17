#include"Avo.h"
#include<iostream>

class MyGameApplication : public Avo::AvoApplication
{
	virtual void Initialize() override
	{
		AVO_ERROR("Starting...");

	}

	virtual void Update() override
	{
		//std::cout << "Running" << std::endl;
	}
};

AVO_GAME_START(MyGameApplication)