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
		int init();
		void run();
		enum ScreenType {stMenu};
		void setScreen(ScreenType screenType);

	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
		SDL_Event* event;
		bool running;
		ScreenType currentScreen;
		vector<Screen*> screenList;
};
