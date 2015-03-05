#include "app.h"

using namespace std;

App::App(){
	screenList.push_back(new MenuScreen());
};

int App::init()
{
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
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

		SDL_RenderPresent(renderer);
	};
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);	
};

App::~App()
{
	delete event;
};