#ifndef LEVEL1SPRITESHEET_H
#define LEVEL1SPRITESHEET_H

#include "sprite.h"
#include "spritesheet.h"
#include <string>
#include <map>

enum SpriteType {stCoin, stBlock, stWater, stGround, stPepper, stBackground, stHero, stEnemy};

class Level1SpriteSheet: public SpriteSheet
{
private:
    std::map<SpriteType, Sprite> FSprites;

public:
    Level1SpriteSheet();
    void Draw(SDL_Renderer *ARenderer, SpriteType Type, int Frame, SDL_Rect* Rect);
};

#endif // LEVEL1SPRITESHEET_H
