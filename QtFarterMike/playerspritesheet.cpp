#include "playerspritesheet.h"

PlayerSpriteSheet::PlayerSpriteSheet()
{
    Sprite ASprite;
    ASprite.Rect.w = 44 - 1;
    ASprite.Rect.h = 64 - 1;

    ASprite.Rect.x = 0;
    ASprite.Rect.y = 0;
    FSprites[stRight] = ASprite;

    ASprite.Rect.x = 0;
    ASprite.Rect.y = 64;
    FSprites[stLeft] = ASprite;

    ASprite.Rect.x = 0;
    ASprite.Rect.y = 128;
    FSprites[stStand] = ASprite;

    FSurface = NULL;
    const std::string path = "res/PlayerSprites.bmp";
    FSurface = SDL_LoadBMP(path.c_str());
    if (FSurface == NULL)
    {
        printf("Unable to load bitmap: PlayerSprites.bmp");
    }
    SDL_SetColorKey(FSurface, SDL_RLEACCEL, SDL_MapRGB(FSurface->format, 255, 255, 255));
}

void PlayerSpriteSheet::Draw(SDL_Surface* Surface, PlayerSpriteType Type, int Frame, SDL_Rect* Rect)
{
    Sprite Pick = FSprites.at(Type);

    Pick.Rect.x += Frame * 44;

    SDL_BlitScaled(FSurface, &Pick.Rect, Surface, Rect);
}
