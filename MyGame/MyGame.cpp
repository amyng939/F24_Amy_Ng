#include "Avo.h"
#include <iostream>
#include <vector>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for seeding rand()

#include "Counter.h"

class MyGameApplication : public Avo::AvoApplication
{
    virtual void Initialize() override
    {
        AVO_LOG("Starting...");

        SetKeyEventHandler([this](const Avo::KeyEvent& event) { MyKeysHandler(event); });

        srand(time(0));

        SpawnProjectiles(1);
    }

    virtual void Update() override
    {
        Avo::Renderer::Draw(background, 0, 0);
        Avo::Renderer::Draw(player);

        // update each projectile
        for (auto& proj : projectiles)
        {
            Avo::Renderer::Draw(proj);
            proj.UpdateXCoord(10);

            // stop game if player collides with projectile
            if (Avo::UnitsOverlap(player, proj))
            {
                Avo::AvoApplication::Shutdown();
                std::cout << "Game Over! Close terminal and run game to play again." << std::endl;
            }

            // reset projectile if it goes off-screen
            if (proj.GetXCoord() > window_width)
            {
                //counter.AddPoint();
                proj.SetCoords(0, rand() % (window_height - proj.GetHeight() + 1));
            }
        }

        //counter.DrawCounter();

        if (frames_passed == 120)
        {
            SpawnProjectiles(1);
            frames_passed = 0;
        }
        frames_passed++;
    }

private:
    int window_width = Avo::AvoWindow::GetWindow()->GetWidth();
    int window_height = Avo::AvoWindow::GetWindow()->GetHeight();

    int frames_passed = 0;

    Avo::Image background{ "../MyGame/Assets/background.png" };

    Avo::Unit player{ "../MyGame/Assets/slowbro.png", 
        window_width / 2, window_height / 2 }; // start at near center of the screen
   
    std::vector<Avo::Unit> projectiles;

    //Counter counter;

    void SpawnProjectiles(int count)
    {
        for (int i = 0; i < count; i++)
        {
            int random_y = rand() % (window_height - 100 + 1); // 100 is the img height
            projectiles.emplace_back("../MyGame/Assets/pokeball.png", 0, random_y);
        }
    }

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