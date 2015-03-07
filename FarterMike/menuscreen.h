#pragma once

#include "app.h"
#include "screen.h"
#include "img/imgimage.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;

class MenuScreen: public Screen
{
	public:
		void init(App& app);
		void draw(App& app) const;
		void touch(App& app, int x, int y);
		void tick(App& app);
		void active(App& app, bool activated);

	private:
		IMGImage background;
};
