#include "app.h"

App::App(){
	screenList.push_back(new MenuScreen());
};

void App::init()
{
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
  surface = SDL_CreateRGBSurface(0, 640, 480, 32, 0, 0, 0, 0);
	while (running && event -> type != SDL_QUIT)
	{
		SDL_PollEvent(event);
		graphicEngine.clear();
		screenList.at(currentScreen) -> tick(*this);
		screenList.at(currentScreen) -> draw(*this);
		graphicEngine.render();
	};
	delete event;
	SDL_Quit();
};

App::~App()
{
};
