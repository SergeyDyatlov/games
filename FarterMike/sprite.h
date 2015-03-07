#pragma once

#include <SDL2/SDL.h>
#include <string>

class Sprite
{
	public:
		Sprite();
		void loadFromFile(std::string &path);
		void draw(SDL_Surface* surface, int x, int y, int width, int height);
	private:
		SDL_Surface* bitmap;
};
