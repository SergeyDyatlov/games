#ifndef ENEMYSPRITESHEET_H
#define ENEMYSPRITESHEET_H

#include "sprite.h"
#include "spritesheet.h"
#include <map>

enum EnemySpriteType {estStand, estMove, estAttack};

class EnemySpriteSheet: public SpriteSheet
{
private:
    std::map<EnemySpriteType, Sprite> FSprites;

public:
    EnemySpriteSheet();
    void Draw(SDL_Renderer *ARenderer, EnemySpriteType Type, int Frame, SDL_Rect* Rect);
    void Draw(SDL_Renderer *ARenderer, EnemySpriteType Type, int Frame, int Direction, SDL_Rect* Rect);
};

#endif // ENEMYSPRITESHEET_H
