#ifndef LEVEL1SPRITESHEET_H
#define LEVEL1SPRITESHEET_H

#include "sprite.h"
#include <SDL2/SDL.h>
#include <string>
#include <map>

enum SpriteType {stCoin, stBlock, stWater, stGround, stPepper, stBackground, stHero, stEnemy};

class Level1SpriteSheet
{
private:
    std::map<SpriteType, Sprite> FSprites;
    SDL_Surface* FSurface;

public:
    Level1SpriteSheet();
    void Draw(SDL_Surface* Surface, SpriteType Type, int Frame, SDL_Rect* Rect);
};

#endif // LEVEL1SPRITESHEET_H
