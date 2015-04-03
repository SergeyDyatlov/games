#ifndef MOVABLE_H
#define MOVABLE_H

#include <SDL2/SDL.h>

class LevelScreen;

class Movable
{
private:
    SDL_Rect FRect;
    float Fx = 0.0f;
    float Fy = 0.0f;
    float Fvx = 0.0f;
    float Fvy = 0.0f;
    bool FDidJump = false;
    bool HasCollision(float x, float y) const;

public:
    Movable();

    void SetRect(const SDL_Rect &);
    const SDL_Rect &GetRect() const;

    void MoveLeft();
    void MoveRight();

    void CheckCollision();

    LevelScreen* Level;
};

#endif // MOVABLE_H
