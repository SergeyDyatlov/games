#pragma once

#include <vector>
#include "gamestate.hpp"

using namespace std;

class GameStateManager 
{
	protected:
		GameStateManager();
		static GameStateManager* p_instance;
		vector<GameState*> stateList;
		int currentState;

	public:
		static GameStateManager* getInstance();
		void draw() const;
		void update();
		void keyPressed(unsigned char key, int x, int y);
		void keySpecial(int key, int x, int y);
		void setState(int state);
};

