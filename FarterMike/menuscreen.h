#pragma once

#include "app.h"
#include "screen.h"
#include "graphicengine.h"
#include "spritesheet.h"
#include "font.h"
#include "button.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <map>

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
		SpriteSheet spriteSheet;
		vector<string> options;
		map<int, Button> buttons;
		Font font;
};
