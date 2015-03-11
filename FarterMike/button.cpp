#include "button.h"

Button::Button()
{

};

Button::Button(int x, int y, int w, int h)
{
	box.x = x;
	box.y = y;
	box.w = w;
	box.h = h;
};

void Button::draw(SDL_Surface* surface)
{
	SDL_FillRect(surface, &box, SDL_MapRGB(surface -> format, 0, 255, 0));
};

void Button::events(SDL_Event &event)
{
	int x = 0, y = 0;
	clicked = false;
	switch (event.type){
		case SDL_MOUSEBUTTONDOWN:
			x = event.motion.x;
			y = event.motion.y;
			if ((x > box.x) && (x < box.x + box.w))
				if ((y > box.y) && (y < box.y + box.h))
				{
					clicked = true;
				}
			break;
	}
};
