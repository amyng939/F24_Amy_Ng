#include"Avo.h"
#include<iostream>

class MyGameApplication : public Avo::AvoApplication
{
	virtual void Initialize() override
	{
		std::cout << "Starting..." << std::endl;
	}

	virtual void Update() override
	{
		//std::cout << "Running" << std::endl;
	}
};

AVO_GAME_START(MyGameApplication)