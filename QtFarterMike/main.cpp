#include <iostream>
#include "game.h"

using namespace std;

int main() {

    Game game;

    game.Init("Game", 640, 480);

    while (game.IsRunning())
    {
        game.HandleEvents();
        game.Update();
        game.Draw();
    }

    game.Clean();

    return 0;
}

