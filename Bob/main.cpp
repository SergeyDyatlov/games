#include <game.h>
#include "menustate.h"
#include <iostream>

using namespace std;

int main()
{
    Game game;

    game.Init("Game", 640, 480);

    game.ChangeState(MenuState::Instance());

    while (game.IsRunning())
    {
        game.HandleEvents();
        game.Update();
        game.Draw();
    }

    game.Clean();

    return 0;
}
