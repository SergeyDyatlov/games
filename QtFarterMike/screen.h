#ifndef SCREEN_H
#define SCREEN_H

#include <SDL2/SDL.h>

class Game;

class Screen
{
public:
    virtual void Init(Game& AGame) = 0;
    virtual void Clean() = 0;
    virtual void HandleEvents(Game& AGame) = 0;
    virtual void Update(Game& AGame) = 0;
    virtual void Draw(Game& AGame) = 0;
};

#endif // SCREEN_H
