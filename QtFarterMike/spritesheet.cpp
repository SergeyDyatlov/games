#include "spritesheet.h"
#include "texture.h"

SpriteSheet::SpriteSheet()
{
}

void SpriteSheet::LoadFromFile(SDL_Renderer *ARenderer, const std::string &path)
{
    Texture = LoadTexture(ARenderer, path.c_str());
}
