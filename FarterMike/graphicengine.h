#pragma once

#include "spritesheet.h"
#include <SDL2/SDL.h>
#include <string>

class	GraphicEngine 
{
	public:
		GraphicEngine();
		~GraphicEngine();
		void clear();
		void drawSprite(Sprite* sprite, SDL_Rect* rect);
		void drawTile(const char ch, int x, int y);
		void drawText(int x, int y, int size, std::string &text);
		int textWidth(int size, std::string &text);
		void render();
		SDL_Surface* surface;
	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
};
