#include "Avo.h"
#include "MyGame.h"

#include <iostream>

#include <cstdlib> // for rand() and srand()
#include <ctime>   // for seeding rand()

void MyGameApplication::Initialize()
{
    AVO_LOG("Starting...");

    SetKeyEventHandler([this](const Avo::KeyEvent& event) { MyKeysHandler(event); });

    srand(time(0));

    SpawnProjectiles(1);
}

void MyGameApplication::Update()
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
            std::cout << "Game Over! Your score was " << counter.GetCount() << ". Close terminal and run game to play again." << std::endl;
        }

        // reset projectile if it goes off-screen
        if (proj.GetXCoord() > window_width)
        {
            counter.AddPoint();
            proj.SetCoords(0, rand() % (window_height - proj.GetHeight() + 1));
        }
    }

    counter.DrawCounter();

    if (frames_passed == 120)
    {
        SpawnProjectiles(1);
        frames_passed = 0;
    }
    frames_passed++;
}

void MyGameApplication::SpawnProjectiles(int count)
{
    for (int i = 0; i < count; i++)
    {
        int random_y = rand() % (window_height - pokeball.GetHeight() + 1);
        projectiles.emplace_back(pokeball_filename, 0, random_y);
    }
}

void MyGameApplication::MyKeysHandler(const Avo::KeyEvent& event)
{
    if (event.GetKeyAction() == Avo::KeyEvent::KeyAction::Press ||
        event.GetKeyAction() == Avo::KeyEvent::KeyAction::Repeat)
    {   // Bottom left corner of player is used to determine its coords to the border
        switch (event.GetKeyCode())
        {
        case AVO_KEY_LEFT:
            if (player.GetXCoord() >= 20)
                player.UpdateXCoord(-20);
            else // when moving by 20 won't let player sit flush along the border, move by the remaining distance to the border
                player.UpdateXCoord(0 - player.GetXCoord());
            break;
        case AVO_KEY_RIGHT:
            if (window_width - (player.GetXCoord() + player.GetWidth()) >= 20)
                player.UpdateXCoord(20);
            else
                player.UpdateXCoord(window_width - (player.GetXCoord() + player.GetWidth()));
            break;
        case AVO_KEY_DOWN:
            if (player.GetYCoord() >= 20)
                player.UpdateYCoord(-20);
            else
                player.UpdateYCoord(0 - player.GetYCoord());
            break;
        case AVO_KEY_UP:
            if (window_height - (player.GetYCoord() + player.GetHeight()) >= 20)
                player.UpdateYCoord(20);
            else
                player.UpdateYCoord(window_height - (player.GetYCoord() + player.GetHeight()));
            break;
        }
    }
}