#include "texture.h"
#include "stb_image.hpp"

SDL_Texture *LoadTexture(SDL_Renderer *ARenderer, const std::string &path)
{
  int width;
  int height;
  int comp;
  SDL_Log("loading '%s'", path.c_str());
  unsigned char *data = stbi_load(path.c_str(), &width, &height, &comp, 4);
  if (!data)
  {
    SDL_Log("Can't load '%s'", path.c_str());
    return nullptr;
  }
  SDL_Log("width: %d height: %d comp: %d", width, height, comp);
  SDL_Texture *Texture = SDL_CreateTexture(ARenderer,
                                           SDL_PIXELFORMAT_ABGR8888,
                                           SDL_TEXTUREACCESS_STATIC,
                                           width, height);

  SDL_UpdateTexture(Texture, nullptr, data, width * 4);
  
  SDL_SetTextureBlendMode(Texture, SDL_BLENDMODE_BLEND);

  free(data);
  return Texture;
}
