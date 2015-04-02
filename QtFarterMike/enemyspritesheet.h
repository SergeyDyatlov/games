#ifndef ENEMYSPRITESHEET_H
#define ENEMYSPRITESHEET_H

#include "sprite.h"
#include <SDL2/SDL.h>
#include <map>

enum EnemySpriteType {estLeft, estRight, estStand};

class EnemySpriteSheet
{
private:
    std::map<EnemySpriteType, Sprite> FSprites;
    SDL_Surface* FSurface;

public:
    EnemySpriteSheet();
    void Draw(SDL_Surface* Surface, EnemySpriteType Type, int Frame, SDL_Rect* Rect);
};

#endif // ENEMYSPRITESHEET_H
