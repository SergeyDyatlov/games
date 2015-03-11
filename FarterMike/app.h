#pragma once
#include "screen.h"
#include "menuscreen.h"
#include "graphicengine.h"
#include <SDL2/SDL.h>
#include <vector>

using namespace std;

class App
{
	public:
		App();
		~App();
		void init();
		void run();
		enum ScreenType {stMenu};
		void setScreen(ScreenType screenType);
		GraphicEngine graphicEngine;

	private:
		SDL_Event* event;
		bool running;
		ScreenType currentScreen;
		vector<Screen*> screenList;
};
