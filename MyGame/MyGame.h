#include "Avo.h"
#include <vector>

#include "Counter.h"

class MyGameApplication : public Avo::AvoApplication
{
public:
    virtual void Initialize() override;
    virtual void Update() override;

private:
    int window_width = Avo::AvoWindow::GetWindow()->GetWidth();
    int window_height = Avo::AvoWindow::GetWindow()->GetHeight();

    int frames_passed = 0;

    Avo::Image background{ "../MyGame/Assets/background.png" };

    Avo::Unit player{ "../MyGame/Assets/slowbro.png",
        window_width / 2, window_height / 2 }; // start at near center of the screen

    std::vector<Avo::Unit> projectiles;

    Counter counter;

    void SpawnProjectiles(int count);

    void MyKeysHandler(const Avo::KeyEvent& event);
};