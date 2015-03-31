#ifndef HERO_H
#define HERO_H

#include <SDL2/SDL.h>

class LevelScreen;

class Hero
{
private:
    int FHealth;
    bool FDead;

public:
    Hero();
    void Hit();
    bool IsDead();

    LevelScreen* Level;
    SDL_Rect Rect;
};

#endif // HERO_H
