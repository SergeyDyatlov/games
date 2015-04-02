#ifndef PLAYERSPRITESHEET_H
#define PLAYERSPRITESHEET_H

#include "sprite.h"
#include <SDL2/SDL.h>
#include <map>

enum PlayerSpriteType {stLeft, stRight, stStand};

class PlayerSpriteSheet
{
private:
    std::map<PlayerSpriteType, Sprite> FSprites;
    SDL_Surface* FSurface;

public:
    PlayerSpriteSheet();
    void Draw(SDL_Surface* Surface, PlayerSpriteType Type, int Frame, SDL_Rect* Rect);
};

#endif // PLAYERSPRITESHEET_H
