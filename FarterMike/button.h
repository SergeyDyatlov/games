#pragma once

#include <SDL2/SDL.h>

class Button
{
	public:
		Button();
		Button(int x, int y, int w, int h);
		void draw(SDL_Surface* surface);
		void events(SDL_Event &event);
		bool clicked;
		SDL_Rect box;
};
