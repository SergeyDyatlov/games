#pragma once
#include "screen.h"
#include "menuscreen.h"
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
		SDL_Renderer* renderer;

	private:
		SDL_Window* window;
		SDL_Event* event;
		bool running;
		ScreenType currentScreen;
		vector<Screen*> screenList;
};
