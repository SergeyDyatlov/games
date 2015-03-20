#include "menuspritesheet.h"

MenuSpriteSheet::MenuSpriteSheet()
{
    SDL_Rect Rect;
    Rect.w = 64 - 1;
    Rect.h = 32 - 1;

    Rect.x = 0;
    Rect.y = 0;
    FSprites[stStart] = Rect;

    Rect.x = 0;
    Rect.y = 32;
    FSprites[stExit] = Rect;

    FSurface = NULL;
    const std::string path = "res/MenuSprites.bmp";
    FSurface = SDL_LoadBMP(path.c_str());
    if (FSurface == NULL)
    {
        printf("Unable to load bitmap: MenuSprites.bmp");
    }
    SDL_SetColorKey(FSurface, SDL_RLEACCEL, SDL_MapRGB(FSurface->format, 255, 255, 255));
}

void MenuSpriteSheet::Draw(SDL_Surface* Surface, MenuSpriteType Type, SDL_Rect* Rect)
{
    SDL_Rect Pick = FSprites.at(Type);

    SDL_BlitScaled(FSurface, &Pick, Surface, Rect);
}
