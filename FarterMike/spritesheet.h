#pragma once

#include "tile.h"
#include <SDL2/SDL.h>
#include <string>
#include <map>

enum Sprite {Background};

class SpriteSheet
{
	public:
		void loadFromFile(const std::string &path);
		void draw(SDL_Surface* surface, Sprite &sprite, int x, int y, int frame);
	private:
		SDL_Surface* bitmap;
		std::map<Sprite, Tile> sprites;
};
