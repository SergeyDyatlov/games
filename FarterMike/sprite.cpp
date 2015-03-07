#include "sprite.h"

Sprite::Sprite()
{

};

void Sprite::loadFromFile(std::string &path)
{
	bitmap = NULL;
	bitmap = SDL_LoadBMP(path.c_str());
	if (bitmap == NULL)
	{
		printf("Unable to load bitmap %s! Error: %s\n", path.c_str(), SDL_GetError());
	}
};

void Sprite::draw(SDL_Surface* surface, int x, int y, int width, int height)
{
	SDL_Rect dstR;
	dstR.x = x;
	dstR.y = y;
	dstR.w = width;
	dstR.h = height;
	SDL_BlitScaled(bitmap, NULL, surface, &dstR);
};
