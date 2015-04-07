#ifndef SCORESPRITESHEET_H
#define SCORESPRITESHEET_H

#include "sprite.h"
#include "spritesheet.h"
#include <string>
#include <map>

enum ScoreSpriteType {stMenu, stRestart, stNext, stCoins};

class ScoreSpriteSheet: public SpriteSheet
{
private:
    std::map<ScoreSpriteType, Sprite> FSprites;

public:
    ScoreSpriteSheet();
    void Draw(SDL_Renderer *ARenderer, ScoreSpriteType Type, int Frame, SDL_Rect* Rect);
};

#endif // SCORESPRITESHEET_H
