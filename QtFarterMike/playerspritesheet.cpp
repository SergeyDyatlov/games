#include "playerspritesheet.h"

PlayerSpriteSheet::PlayerSpriteSheet()
{
    Sprite ASprite;
    ASprite.Rect.w = 44 - 1;
    ASprite.Rect.h = 64 - 1;

    ASprite.Rect.x = 0;
    ASprite.Rect.y = 0;
    FSprites[stStand] = ASprite;

    ASprite.Rect.x = 0;
    ASprite.Rect.y = 64;
    FSprites[stMove] = ASprite;
}

void PlayerSpriteSheet::Draw(SDL_Renderer *ARenderer, PlayerSpriteType Type, int Frame, SDL_Rect* Rect)
{
    Sprite Pick = FSprites.at(Type);

    Pick.Rect.x += Frame * 44;

    SDL_RenderCopy(ARenderer, Texture, &Pick.Rect, Rect);
}

void PlayerSpriteSheet::Draw(SDL_Renderer *ARenderer, PlayerSpriteType Type, int Frame, int Direction, SDL_Rect* Rect)
{
    Sprite Pick = FSprites.at(Type);

    Pick.Rect.x += Frame * 44;

    SDL_RendererFlip Flip = SDL_FLIP_NONE;
    if (Direction == 1)
    {
        Flip = SDL_FLIP_HORIZONTAL;
    }

    SDL_RenderCopyEx(ARenderer, Texture, &Pick.Rect, Rect, 0, NULL, Flip);
}
