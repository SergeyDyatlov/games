#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class SpriteSheet
{
public:
    SpriteSheet();
    void LoadTexture(SDL_Renderer *ARenderer, const std::string &path);

    SDL_Texture *Texture;
};

#endif // SPRITESHEET_H
