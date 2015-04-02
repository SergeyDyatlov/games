#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL2/SDL.h>

class Animation
{
private:
    long FStartTime;

public:
    Animation();
    void Animate();

    int StartFrame;
    int EndFrame;
    int Frame;

    int FrameRate;
};

#endif // ANIMATION_H
