#include "scorespritesheet.h"

ScoreSpriteSheet::ScoreSpriteSheet()
{
    Sprite ASprite;
    ASprite.Rect.w = 64;
    ASprite.Rect.h = 32;

    ASprite.Rect.x = 0;
    ASprite.Rect.y = 0;
    FSprites[stMenu] = ASprite;

    ASprite.Rect.x = 0;
    ASprite.Rect.y = 32;
    FSprites[stRestart] = ASprite;

    ASprite.Rect.x = 0;
    ASprite.Rect.y = 64;
    FSprites[stNext] = ASprite;

    ASprite.Rect.w = 32;
    ASprite.Rect.h = 32;

    ASprite.Rect.x = 0;
    ASprite.Rect.y = 96;
    FSprites[stCoins] = ASprite;
}

void ScoreSpriteSheet::Draw(SDL_Renderer *ARenderer, ScoreSpriteType Type, int Frame, SDL_Rect* Rect)
{
    Sprite Pick = FSprites.at(Type);
    if (Type != stCoins)
    {
        Pick.Rect.x += Frame * 64;
    }

    SDL_RenderCopy(ARenderer, Texture, &Pick.Rect, Rect);
}
