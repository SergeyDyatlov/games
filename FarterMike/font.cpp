#include "font.h"

Font::Font()
{

};

void Font::loadFromFile(std::string &path)
{
	bitmap = NULL;
	bitmap = SDL_LoadBMP(path.c_str());
	if (bitmap == NULL)
	{
		printf("Unable to load bitmap %s! Error: %s\n", path.c_str(), SDL_GetError());
	};
};

void Font::drawChar(SDL_Surface* surface, int x, int y, int asciicode)
{
	SDL_Rect pick;
	pick.x = (asciicode % 16) * 16;
	pick.y = (asciicode / 16) * 16;
	pick.w = 16;
	pick.h = 16;

	SDL_Rect area;
	area.x = x;
	area.y = y;
	area.w = 16;
	area.h = 16;
	SDL_BlitSurface(bitmap, &pick, surface, &area);
};

void Font::drawText(SDL_Surface* surface, int x, int y, std::string &text)
{
	int asciicode;
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	for (int i=0; i<text.length(); i++)
	{
		asciicode = text[i];
		drawChar(surface, rect.x, rect.y, asciicode);
		rect.x = rect.x + 16;
	}
};
