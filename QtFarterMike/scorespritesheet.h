#ifndef SCORESPRITESHEET_H
#define SCORESPRITESHEET_H

#include "sprite.h"
#include <SDL2/SDL.h>
#include <string>
#include <map>

enum ScoreSpriteType {stMenu, stRestart, stNext, stCoins};

class ScoreSpriteSheet
{
private:
    std::map<ScoreSpriteType, Sprite> FSprites;
    SDL_Surface* FSurface;

public:
    ScoreSpriteSheet();
    void Draw(SDL_Surface* Surface, ScoreSpriteType Type, int Frame, SDL_Rect* Rect);
};

#endif // SCORESPRITESHEET_H
