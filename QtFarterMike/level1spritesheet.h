#ifndef LEVEL1SPRITESHEET_H
#define LEVEL1SPRITESHEET_H

#include <SDL2/SDL.h>
#include <string>
#include <map>

enum SpriteType {stCoin, stBackground, stWater, stGround};

class Level1SpriteSheet
{
private:
    std::map<SpriteType, SDL_Rect> FSprites;
    SDL_Surface* FSurface;

public:
    Level1SpriteSheet();
    void Draw(SDL_Surface* Surface, SpriteType Type, SDL_Rect* Rect);
};

#endif // LEVEL1SPRITESHEET_H