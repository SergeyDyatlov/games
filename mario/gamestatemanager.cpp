#include "gamestatemanager.hpp"
#include "menustate.hpp"

using namespace std;

GameStateManager* GameStateManager::p_instance = 0;

GameStateManager* GameStateManager::getInstance()
{
	if (!p_instance) {
		p_instance = new GameStateManager();
	}
	return p_instance;
};

GameStateManager::GameStateManager()
{
	stateList.push_back(new MenuState());
	currentState = 0;
};

void GameStateManager::draw() const
{
	stateList.at(currentState) -> draw();
};

void GameStateManager::update() 
{
	stateList.at(currentState) -> update();
};

void GameStateManager::keyPressed(unsigned char key, int x, int y) 
{
	stateList.at(currentState) -> keyPressed(key, x, y);
};

void GameStateManager::keySpecial(int key, int x, int y)
{
	stateList.at(currentState) -> keySpecial(key, x, y);
};

void GameStateManager::setState(int state)
{
	currentState = state;
	stateList.at(currentState) -> init();
};

