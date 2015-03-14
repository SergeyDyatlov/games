#include "graphicengine.h"

GraphicEngine::GraphicEngine()
{
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow(
			"Game", 
			SDL_WINDOWPOS_CENTERED, 
			SDL_WINDOWPOS_CENTERED, 
			640, 
			480, 
			SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	surface = SDL_CreateRGBSurface(0, 640, 480, 32, 0, 0, 0, 0);
};

GraphicEngine::~GraphicEngine()
{
	SDL_FreeSurface(surface);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
};

void GraphicEngine::clear()
{
	SDL_FillRect(surface, NULL, 0x000000);
};

void GraphicEngine::render()
{
	SDL_RenderClear(renderer);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_DestroyTexture(texture);
	SDL_RenderPresent(renderer);
	SDL_Delay(30);
};

void GraphicEngine::drawSprite(Sprite* sprite, SDL_Rect* rect)
{

};

void GraphicEngine::drawTile(const char ch, int x, int y)
{
	SDL_Rect rect;
	rect.x = x * 16;
	rect.y = y * 16;
	rect.w = 16;
	rect.h = 16;

	Uint32 color;
	color = SDL_MapRGB(surface -> format, 0, 0, 0);
	if (ch == '*')
	{
		color = SDL_MapRGB(surface -> format, 192, 192, 192);
	}
	if (ch == '$')
	{
		color = SDL_MapRGB(surface -> format, 192, 192, 0);
	}
	SDL_FillRect(surface, &rect, color);
};

void GraphicEngine::drawText(int x, int y, int size, std::string &text)
{

};

int GraphicEngine::textWidth(int size, std::string &text)
{
	return 0;
};
