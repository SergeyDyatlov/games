#pragma once

#include "app.h"
#include "screen.h"
#include "sprite.h"
#include "font.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

using namespace std;

class MenuScreen: public Screen
{
	public:
		void init(App& app);
		void draw(App& app);
		void touch(App& app, int x, int y);
		void tick(App& app);
		void active(App& app, bool activated);

	private:
		Sprite background;
		Font font;
		vector<string> options;
		int choice;
};
