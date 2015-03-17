#include "level1spritesheet.h"

Level1SpriteSheet::Level1SpriteSheet()
{
    SDL_Rect Rect;
    Rect.w = 32 - 1;
    Rect.h = 32 - 1;

    Rect.x = 0;
    Rect.y = 0;
    FSprites[stCoin] = Rect;

    Rect.x = 0;
    Rect.y = 32;
    FSprites[stBlock] = Rect;

    Rect.x = 0;
    Rect.y = 64;
    FSprites[stWater] = Rect;

    Rect.x = 0;
    Rect.y = 96;
    FSprites[stGround] = Rect;

    Rect.x = 0;
    Rect.y = 128;
    FSprites[stPepper] = Rect;

    Rect.x = 0;
    Rect.y = 160;
    Rect.w = 32;
    Rect.h = 64;
    FSprites[stHero] = Rect;

    Rect.x = 640 - 128;
    Rect.y = 0;
    Rect.w = 128;
    Rect.h = 128;
    FSprites[stBackground] = Rect;

    FSurface = NULL;
    const std::string path = "res/Level1Sprites.bmp";
    FSurface = SDL_LoadBMP(path.c_str());
    if (FSurface == NULL)
    {
        printf("Unable to load bitmap: Level1Sprites.bmp");
    }
    SDL_SetColorKey(FSurface, SDL_RLEACCEL, SDL_MapRGB(FSurface->format, 255, 255, 255));
}

void Level1SpriteSheet::Draw(SDL_Surface* Surface, SpriteType Type, SDL_Rect* Rect)
{
    SDL_Rect Pick = FSprites.at(Type);

    SDL_BlitScaled(FSurface, &Pick, Surface, Rect);
}
