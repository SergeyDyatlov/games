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
}

void MenuSpriteSheet::Draw(SDL_Renderer* ARenderer, MenuSpriteType Type, int Frame, SDL_Rect* Rect)
{
    Sprite Pick = FSprites.at(Type);
    Pick.Rect.x += Frame * 64;

    SDL_RenderCopy(ARenderer, Texture, &Pick.Rect, Rect);
}
