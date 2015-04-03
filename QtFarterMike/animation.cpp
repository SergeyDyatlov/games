#include "animation.h"

Animation::Animation()
{
    StartFrame = 0;
    EndFrame = 0;
    Frame = 0;

    FrameRate = 100;

    FStartTime = SDL_GetTicks();
}

void Animation::Animate()
{
    long Elapsed = (SDL_GetTicks() - FStartTime);
    if (Elapsed >= FrameRate)
    {
        Frame++;
        FStartTime = SDL_GetTicks();
    }
    if (Frame >= EndFrame)
    {
        Frame = StartFrame;
    }
}
