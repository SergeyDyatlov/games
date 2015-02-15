#pragma once

#include "gamestate.hpp"

class MenuState: public GameState {
	private:
		int currentChoice;
	protected:
		void renderString(const char* string, float x, float y) const;
		void select();

	public:
		void init();
		void draw() const;
		void update();
		void keyPressed(unsigned char key, int x, int y);
		void keySpecial(int key, int x, int y);
};

