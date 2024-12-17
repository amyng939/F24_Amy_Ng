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
		Avo::Renderer::Draw(background, 0, 0);

		Avo::Renderer::Draw(player);

		Avo::Renderer::Draw(projectile);
		projectile.UpdateXCoord(10);

		if (Avo::UnitsOverlap(player, projectile))
		{
			Avo::AvoApplication::Shutdown();
			std::cout << "Game Over! Close terminal and run game to play again." << std::endl;
		}

		if (projectile.GetXCoord() > window_width)
		{
			projectile.SetCoords(0, 500);
		}
	}

private:
	int window_width = Avo::AvoWindow::GetWindow()->GetWidth();
	int window_height = Avo::AvoWindow::GetWindow()->GetHeight();

	Avo::Image background{ "../MyGame/Assets/background.png" };

	Avo::Unit player{ "../MyGame/Assets/slowbro.png", 
		window_width / 2, window_height / 2 }; // start at near center of the screen

	Avo::Unit projectile{ "../MyGame/Assets/horizontal_laser.png", 0, 500};
	
	void MyKeysHandler(const Avo::KeyEvent& event)
	{
		if (event.GetKeyAction() == Avo::KeyEvent::KeyAction::Press ||
			event.GetKeyAction() == Avo::KeyEvent::KeyAction::Repeat)
		{   // Bottom left corner of player is used to determine its coords to the border
			switch (event.GetKeyCode())
			{
			case AVO_KEY_LEFT:
				if (player.GetXCoord() >= 20)
					player.UpdateXCoord(-20);
				else if (player.GetXCoord() >= 8) // since moving by 20 won't let player sit flush along the border
					player.UpdateXCoord(-8);
				break;
			case AVO_KEY_RIGHT:
				if (player.GetXCoord() <= window_width - player.GetWidth() - 20)
					player.UpdateXCoord(20);
				else if (player.GetXCoord() <= window_width - player.GetWidth() - 8)
					player.UpdateXCoord(8);
				break;
			case AVO_KEY_DOWN:
				if (player.GetYCoord() >= 20)
					player.UpdateYCoord(-20);
				else if (player.GetYCoord() >= 8)
					player.UpdateYCoord(-8);
				break;
			case AVO_KEY_UP:
				if (player.GetYCoord() <= window_height - player.GetHeight() - 20)
					player.UpdateYCoord(20);
				else if (player.GetYCoord() <= window_height - player.GetHeight() - 8)
					player.UpdateYCoord(8);
				break;
			}
		}
	}
};

AVO_GAME_START(MyGameApplication)