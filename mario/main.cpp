#include <GL/glut.h>
#include <vector>
#include <string.h>
#include "gamestate.hpp"
#include "menustate.hpp"

using namespace std;

class GameStateManager 
{
  vector<GameState*> stateList;
  int currentState;
  protected:
  static GameStateManager* p_instance;
  GameStateManager()
  {
    stateList.push_back(new MenuState());
    currentState = 0;
  };
  virtual ~GameStateManager(){};

  public:
  static GameStateManager* getInstance()
  {
    if (!p_instance) {
      p_instance = new GameStateManager();
    }
    return p_instance;
  };

  void draw() const
  {
    stateList.at(currentState) -> draw();
  };

  void update() const
  {
    stateList.at(currentState) -> update();
  };

  void keyPressed(unsigned char key, int x, int y) const
  {
    stateList.at(currentState) -> keyPressed(key, x, y);
  };

  void keySpecial(int key, int x, int y)
  {
    stateList.at(currentState) -> keySpecial(key, x, y);
  };

  void setState(int state)
  {
    currentState = state;
    stateList.at(currentState) -> init();
  };
};

GameStateManager* GameStateManager::p_instance = 0;

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  GameStateManager::getInstance() -> draw();
  glutSwapBuffers();
};

void timer(int = 0)
{
  display();
  glutTimerFunc(1, timer, 0);
  GameStateManager::getInstance() -> update(); 
};

void keyPressed(unsigned char key, int x, int y)
{
  GameStateManager::getInstance() -> keyPressed(key, x, y);
};

void keySpecial(int key, int x, int y)
{
  GameStateManager::getInstance() -> keySpecial(key, x, y);
};

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Game");
  glClearColor(0, 0, 0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, 640, 480, 0, -1, 1);
  glutDisplayFunc(display);
  timer();
  glutKeyboardFunc(keyPressed);
  glutSpecialFunc(keySpecial);
  glutMainLoop();
  return 0;
}
