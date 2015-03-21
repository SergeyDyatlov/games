#include "scorespritesheet.h"

ScoreSpriteSheet::ScoreSpriteSheet()
{
    SDL_Rect Rect;
    Rect.w = 64;
    Rect.h = 32;

    Rect.x = 0;
    Rect.y = 0;
    FSprites[stMenu] = Rect;

    Rect.x = 0;
    Rect.y = 32;
    FSprites[stRestart] = Rect;

    Rect.x = 0;
    Rect.y = 64;
    FSprites[stNext] = Rect;

    Rect.w = 32;
    Rect.h = 32;

    Rect.x = 0;
    Rect.y = 96;
    FSprites[stCoins] = Rect;

    FSurface = NULL;
    const std::string path = "res/ScoreSprites.bmp";
    FSurface = SDL_LoadBMP(path.c_str());
    if (FSurface == NULL)
    {
        printf("Unable to load bitmap: ScoreSprites.bmp");
    }
    SDL_SetColorKey(FSurface, SDL_RLEACCEL, SDL_MapRGB(FSurface->format, 255, 255, 255));
}

void ScoreSpriteSheet::Draw(SDL_Surface* Surface, ScoreSpriteType Type, SDL_Rect* Rect)
{
    SDL_Rect Pick = FSprites.at(Type);

    SDL_BlitScaled(FSurface, &Pick, Surface, Rect);
}
