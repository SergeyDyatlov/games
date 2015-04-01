#include "menuspritesheet.h"

MenuSpriteSheet::MenuSpriteSheet()
{
    Sprite ASprite;
    ASprite.Rect.w = 64 - 1;
    ASprite.Rect.h = 32 - 1;

    ASprite.Rect.x = 0;
    ASprite.Rect.y = 0;
    FSprites[stStart] = ASprite;

    ASprite.Rect.x = 0;
    ASprite.Rect.y = 32;
    FSprites[stExit] = ASprite;

    FSurface = NULL;
    const std::string path = "res/MenuSprites.bmp";
    FSurface = SDL_LoadBMP(path.c_str());
    if (FSurface == NULL)
    {
        printf("Unable to load bitmap: MenuSprites.bmp");
    }
    SDL_SetColorKey(FSurface, SDL_RLEACCEL, SDL_MapRGB(FSurface->format, 255, 255, 255));
}

void MenuSpriteSheet::Draw(SDL_Surface* Surface, MenuSpriteType Type, int Frame, SDL_Rect* Rect)
{
    Sprite Pick = FSprites.at(Type);
    Pick.Rect.x += Frame * 64;

    SDL_BlitScaled(FSurface, &Pick.Rect, Surface, Rect);
}
