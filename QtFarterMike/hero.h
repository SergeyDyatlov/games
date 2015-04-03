#ifndef HERO_H
#define HERO_H

#include "animation.h"
#include <SDL2/SDL.h>

class LevelScreen;

enum PlayerAction {paMoveLeft, paMoveRight, paStand};

class Hero: public Animation
{
private:
    int FHealth;
    bool FDead;

public:
    Hero();
    void Hit();
    bool IsDead();

    LevelScreen* Level;
    void Left();
    void Right();
    void Stop();
    void Jump();
    void Update();
    void SetRect(const SDL_Rect &);
    const SDL_Rect &GetRect() const;
    int Direction;
    PlayerAction Action;
private:
    SDL_Rect FRect;
    float Fx = 0.0f;
    float Fy = 0.0f;
    float Fvx = 0.0f;
    float Fvy = 0.0f;
    bool FDidJump = false;
    bool HasCollision(float x, float y) const;
};

#endif // HERO_H
