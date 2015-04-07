#include "texture.h"

// http://immersedcode.org/2011/4/7/stb-image/
// https://github.com/vheuken/Purity2D/blob/master/src/framework/graphics/texture.cpp

SDL_Texture *LoadTexture(SDL_Renderer *ARenderer, const std::string &path)
{
    SDL_Texture *Texture;

    Texture = IMG_LoadTexture(ARenderer, path.c_str());
    SDL_SetTextureBlendMode(Texture, SDL_BLENDMODE_BLEND);

    return Texture;
}
