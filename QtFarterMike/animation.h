#ifndef ANIMATION_H
#define ANIMATION_H

#include "movable.h"
#include <SDL2/SDL.h>

class Animation: public Movable
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
