#include "app.h"

App::App(){
	screenList.push_back(new MenuScreen());
};

void App::init()
{
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	event = new SDL_Event();
	running = true;
	setScreen(stMenu);
};

void App::setScreen(ScreenType screenType)
{
	currentScreen = screenType;
	screenList.at(currentScreen) -> init(*this);
};

void App::run()
{
	while (running && event -> type != SDL_QUIT)
	{
		SDL_PollEvent(event);
		SDL_RenderClear(renderer);
		surface = SDL_CreateRGBSurface(0, 640, 480, 32, 0, 0, 0, 0);

		screenList.at(currentScreen) -> tick(*this);
		screenList.at(currentScreen) -> draw(*this);

		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);

		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
		SDL_Delay(30);
	};
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);	
	delete event;
};

App::~App()
{
};
