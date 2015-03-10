#pragma once

#include <SDL2/SDL.h>
#include <string>

class Font
{
	public:
		Font();
		void loadFromFile(std::string &path);
		void drawChar(SDL_Surface* surface, int x, int y, int asciicode);
		void drawText(SDL_Surface* surface, int x, int y, std::string &text);
		int charWidth(int size, int asciicode);
		int textWidth(int size, const std::string &text);
	private:
		SDL_Surface* bitmap;
};
