#pragma once

#include "app.h"
#include "screen.h"
#include <SDL2/SDL_ttf.h>

using namespace std;

class MenuScreen: public Screen
{
	public:
		void init(App& app);
		void draw(App& app) const;
		void touch(App& app, int x, int y);
		void tick(App& app);
		void active(App& app, bool activated);
};
