#include "spritesheet.h"

void SpriteSheet::loadFromFile(const std::string &path)
{
	printf("SpriteSheet.loadFromFile: %s\n", path.c_str());
	bitmap = NULL;
	bitmap = SDL_LoadBMP(path.c_str());
	if (bitmap == NULL)
	{
		printf("Unable to load bitmap %s! Error: %s\n", path.c_str(), SDL_GetError());
	};
	sprites[Background] = Tile(0, 0, 640, 480, 0);
	sprites[PlayButton] = Tile(0, 256, 64, 16, 0);
};

void SpriteSheet::draw(SDL_Surface* surface, Sprite sprite,  int x, int y, int frame)
{
	Tile tile = sprites.at(sprite);
	SDL_Rect pick;
	pick.x = tile.x;
	pick.y = tile.y;
	pick.w = tile.w;
	pick.h = tile.h;

	SDL_Rect area;
	area.x = x;
	area.y = y;
	area.w = tile.w;
	area.h = tile.h;
	SDL_BlitSurface(bitmap, &pick, surface, &area);
};
