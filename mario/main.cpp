#include <GL/glut.h>
#include "gamestatemanager.hpp"

using namespace std;

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
