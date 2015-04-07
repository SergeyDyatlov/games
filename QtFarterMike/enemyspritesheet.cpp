#include "enemyspritesheet.h"

EnemySpriteSheet::EnemySpriteSheet()
{
    Sprite ASprite;
    ASprite.Rect.w = 36 - 1;
    ASprite.Rect.h = 71 - 1;

    ASprite.Rect.x = 0;
    ASprite.Rect.y = 71;
    FSprites[estStand] = ASprite;

    ASprite.Rect.x = 0;
    ASprite.Rect.y = 0;
    FSprites[estRight] = ASprite;

    ASprite.Rect.x = 0;
    ASprite.Rect.y = 71;
    FSprites[estLeft] = ASprite;

    ASprite.Rect.x = 0;
    ASprite.Rect.y = 71;
    FSprites[estAttack] = ASprite;
}

void EnemySpriteSheet::Draw(SDL_Renderer *ARenderer, EnemySpriteType Type, int Frame, SDL_Rect* Rect)
{
    Sprite Pick = FSprites.at(Type);

    Pick.Rect.x += Frame * 36;

    SDL_RenderCopy(ARenderer, Texture, &Pick.Rect, Rect);
}
