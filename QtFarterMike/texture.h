#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>
#include <string>

SDL_Texture *LoadTexture(SDL_Renderer *ARenderer, const std::string &path);

#endif // TEXTURE_H
