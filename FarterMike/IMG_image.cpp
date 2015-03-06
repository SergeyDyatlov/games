#include "IMG_image.h"

IMG_Image::IMG_Image()
{
	texture = NULL;
	width = 0;
	height = 0;
};

void IMG_Image::loadFromFile(SDL_Renderer* renderer, std::string path)
{
	SDL_Surface* surface = IMG_Load(path.c_str());
	if (surface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		SDL_Surface* formated = SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_RGBA8888, 0);
		if (formated == NULL)
		{
			printf("Unable to convert loaded surface to display format! %s\n", SDL_GetError());
		}
		else
		{
			width = formated -> w;
			height = formated -> h;
			texture = SDL_CreateTextureFromSurface(renderer, surface);
		}
	}
	SDL_FreeSurface(surface);
};

void IMG_Image::render(SDL_Renderer* renderer, const SDL_Rect* srcrect, const SDL_Rect* dstrect) const
{
	SDL_RenderCopy(renderer, texture, srcrect, dstrect);
};

int IMG_Image::getWidth()
{
	return width;
};

int IMG_Image::getHeight()
{
	return height;
};

