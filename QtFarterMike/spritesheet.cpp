#include "spritesheet.h"

SpriteSheet::SpriteSheet()
{
}

void SpriteSheet::LoadTexture(SDL_Renderer *ARenderer, const std::string &path)
{
    Texture = IMG_LoadTexture(ARenderer, path.c_str());
    SDL_SetTextureBlendMode(Texture, SDL_BLENDMODE_BLEND);
}
