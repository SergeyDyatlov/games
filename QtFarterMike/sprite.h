#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>

struct TFrames
{
    int MinFrame;
    int MaxFrame;
    int CurFrame;
};

class Sprite
{
private:
    long FStartTime;

public:
    SDL_Rect Rect;
    TFrames Frames;

    Sprite()
    {
        FStartTime = SDL_GetTicks();
    }

    void Update()
    {
        long Elapsed = (SDL_GetTicks() - FStartTime);
        if (Elapsed >= 100)
        {
            Frames.CurFrame++;
            FStartTime = SDL_GetTicks();
        }
        if (Frames.CurFrame >= Frames.MaxFrame - 1)
        {
            Frames.CurFrame = 0;
        }
    }
};

#endif // SPRITE_H
