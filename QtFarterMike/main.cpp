#include <iostream>
#include "game.h"

using namespace std;

int main(int argc, char *argv[]) {

    Game game;

    game.Init("Game", 640 , 360);

    while (game.IsRunning())
    {
        game.HandleEvents();
        game.Update();
        game.Draw();
    }

    game.Clean();

    return 0;
}

