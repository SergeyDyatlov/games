#include "enemyspritesheet.h"

EnemySpriteSheet::EnemySpriteSheet()
{
    Sprite ASprite;
    ASprite.Rect.w = 36 - 1;
    ASprite.Rect.h = 71 - 1;

    ASprite.Rect.x = 0;
    ASprite.Rect.y = 0;
    FSprites[estRight] = ASprite;

    ASprite.Rect.x = 0;
    ASprite.Rect.y = 71;
    FSprites[estLeft] = ASprite;

    ASprite.Rect.x = 0;
    ASprite.Rect.y = 71;
    FSprites[estStand] = ASprite;

    FSurface = NULL;
    const std::string path = "res/EnemySprites.bmp";
    FSurface = SDL_LoadBMP(path.c_str());
    if (FSurface == NULL)
    {
        printf("Unable to load bitmap: EnemySprites.bmp");
    }
    SDL_SetColorKey(FSurface, SDL_RLEACCEL, SDL_MapRGB(FSurface->format, 255, 255, 255));
}

void EnemySpriteSheet::Draw(SDL_Surface* Surface, EnemySpriteType Type, int Frame, SDL_Rect* Rect)
{
    Sprite Pick = FSprites.at(Type);

    Pick.Rect.x += Frame * 36;

    SDL_BlitScaled(FSurface, &Pick.Rect, Surface, Rect);
}
