#include "app.h"

App::App(){
	screenList.push_back(new MenuScreen());
};

void App::init()
{
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
	SDL_Event event;
	int x;
	int y;
	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_MOUSEMOTION:
					x = event.motion.x;
					y = event.motion.y;
					screenList.at(currentScreen) -> touch(*this, x, y);
					break;

				case SDL_QUIT:
					running = false;
					break;
			}
		}
		graphicEngine.clear();
		screenList.at(currentScreen) -> tick(*this);
		screenList.at(currentScreen) -> draw(*this);
		graphicEngine.render();
	};
	SDL_Quit();
};

App::~App()
{
};
