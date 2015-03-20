#ifndef MENUSPRITESHEET_H
#define MENUSPRITESHEET_H

#include <SDL2/SDL.h>
#include <string>
#include <map>

enum MenuSpriteType {stStart, stExit};

class MenuSpriteSheet
{
private:
    std::map<MenuSpriteType, SDL_Rect> FSprites;
    SDL_Surface* FSurface;

public:
    MenuSpriteSheet();
    void Draw(SDL_Surface* Surface, MenuSpriteType Type, SDL_Rect* Rect);
};

#endif // MENUSPRITESHEET_H
