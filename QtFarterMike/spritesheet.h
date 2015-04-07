#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <SDL2/SDL.h>
#include <string>

class SpriteSheet
{
public:
    SpriteSheet();
    void LoadFromFile(SDL_Renderer *ARenderer, const std::string &path);

    SDL_Texture *Texture;
};

#endif // SPRITESHEET_H
