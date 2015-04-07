#ifndef MENUSPRITESHEET_H
#define MENUSPRITESHEET_H

#include "sprite.h"
#include "spritesheet.h"
#include <string>
#include <map>

enum MenuSpriteType {stStart, stExit};

class MenuSpriteSheet: public SpriteSheet
{
private:
    std::map<MenuSpriteType, Sprite> FSprites;

public:
    MenuSpriteSheet();
    void Draw(SDL_Renderer* ARenderer, MenuSpriteType Type, int Frame, SDL_Rect* Rect);
};

#endif // MENUSPRITESHEET_H
