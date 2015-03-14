#pragma once

#include "app.h"
#include "spritesheet.h"

class Level1Screen: public Screen
{
	public:
		void init(App& app);
		void draw(App& app);
		void touch(App& app, int x, int y);
		void tick(App& app);
		void active(App& app, bool activated);
	private:
		int xOffset;
};
