#include"Avo.h"
#include<iostream>

class MyGameApplication : public Avo::AvoApplication
{
	virtual void Initialize() override
	{
		AVO_LOG("Starting...");

		SetKeyEventHandler([this](const Avo::KeyEvent& event) {MyKeysHandler(event); });
	}

	virtual void Update() override
	{
		Avo::Renderer::Draw(pic);
	}

private:
	Avo::Unit pic{ "../Avo/AvoAssets/Images/Slowpoke.png", 100, 100 };

	void MyKeysHandler(const Avo::KeyEvent& event)
	{
		if (event.GetKeyAction() == Avo::KeyEvent::KeyAction::Press)
		{
			switch (event.GetKeyCode())
			{
			case AVO_KEY_LEFT:
				pic.UpdateXCoord(-10);
				break;
			case AVO_KEY_RIGHT:
				pic.UpdateXCoord(10);
				break;
			}
		}
	}
};

AVO_GAME_START(MyGameApplication)