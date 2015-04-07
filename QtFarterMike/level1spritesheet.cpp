#include "level1spritesheet.h"

Level1SpriteSheet::Level1SpriteSheet()
{
    Sprite ASprite;
    ASprite.Rect.w = 32 - 1;
    ASprite.Rect.h = 32 - 1;

    ASprite.Rect.x = 0;
    ASprite.Rect.y = 0;
    ASprite.Frame = 0;
    ASprite.StartFrame = 0;
    ASprite.EndFrame = 9;
    FSprites[stCoin] = ASprite;

    ASprite.Rect.x = 0;
    ASprite.Rect.y = 32;
    FSprites[stBlock] = ASprite;

    ASprite.Rect.x = 0;
    ASprite.Rect.y = 64;
    FSprites[stWater] = ASprite;

    ASprite.Rect.x = 0;
    ASprite.Rect.y = 96;
    FSprites[stGround] = ASprite;

    ASprite.Rect.x = 0;
    ASprite.Rect.y = 128;
    FSprites[stPepper] = ASprite;

    ASprite.Rect.x = 0;
    ASprite.Rect.y = 160;
    ASprite.Rect.w = 32;
    ASprite.Rect.h = 64;
    FSprites[stHero] = ASprite;

    ASprite.Rect.x = 0;
    ASprite.Rect.y = 224;
    ASprite.Rect.w = 32;
    ASprite.Rect.h = 64;
    FSprites[stEnemy] = ASprite;

    ASprite.Rect.x = 640 - 128;
    ASprite.Rect.y = 0;
    ASprite.Rect.w = 128;
    ASprite.Rect.h = 128;
    FSprites[stBackground] = ASprite;
}

void Level1SpriteSheet::Draw(SDL_Renderer *ARenderer, SpriteType Type, int Frame, SDL_Rect* Rect)
{
    Sprite Pick = FSprites.at(Type);

    Pick.Rect.x += Frame * 32;

    SDL_RenderCopy(ARenderer, Texture, &Pick.Rect, Rect);
}
