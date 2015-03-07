#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>

class IMGImage
{
	public:
		IMGImage();
		void loadFromFile(SDL_Renderer* renderer, std::string path);
		void render(SDL_Renderer* renderer, const SDL_Rect* srcrect, const SDL_Rect* dstrect) const;
		int getWidth();
		int getHeight();
	private:
		SDL_Texture* texture;
		int width;
		int height;
};
