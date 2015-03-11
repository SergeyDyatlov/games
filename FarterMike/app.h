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
		enum ScreenType {stMenu, stLevel1};
		void setScreen(ScreenType screenType);
		GraphicEngine graphicEngine;

	private:
		bool running;
		ScreenType currentScreen;
		vector<Screen*> screenList;
};
