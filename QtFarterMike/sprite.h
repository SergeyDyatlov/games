#ifndef SPRITE_H
#define SPRITE_H

#include "animation.h"
#include <SDL2/SDL.h>

class Sprite: public Animation
{
public:
    SDL_Rect Rect;
};

#endif // SPRITE_H
