#ifndef PLAYERSPRITESHEET_H
#define PLAYERSPRITESHEET_H

#include "sprite.h"
#include "spritesheet.h"
#include <map>

enum PlayerSpriteType {stMove, stStand};

class PlayerSpriteSheet: public SpriteSheet
{
private:
    std::map<PlayerSpriteType, Sprite> FSprites;
    SDL_Surface* FSurface;

public:
    PlayerSpriteSheet();
    void Draw(SDL_Renderer *ARenderer, PlayerSpriteType Type, int Frame, SDL_Rect* Rect);
    void Draw(SDL_Renderer *ARenderer, PlayerSpriteType Type, int Frame, int Direction, SDL_Rect* Rect);
};

#endif // PLAYERSPRITESHEET_H
