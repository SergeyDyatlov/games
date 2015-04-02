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
    void Left();
    void Right();
    void Stop();
    void Jump();
    void Update();
    void SetRect(const SDL_Rect &);
    const SDL_Rect &GetRect() const;
private:
    SDL_Rect FRect;
    float Fx = 0.0f;
    float Fy = 0.0f;
    float Fvx = 0.0f;
    float Fvy = 0.0f;
    bool FDidJump = false;
};

#endif // HERO_H
