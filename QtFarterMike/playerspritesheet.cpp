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
}

void PlayerSpriteSheet::Draw(SDL_Renderer *ARenderer, PlayerSpriteType Type, int Frame, SDL_Rect* Rect)
{
    Sprite Pick = FSprites.at(Type);

    Pick.Rect.x += Frame * 44;

    SDL_RenderCopy(ARenderer, Texture, &Pick.Rect, Rect);
}
