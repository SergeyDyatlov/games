#include <GL/glut.h>
#include <string.h>
#include "menustate.hpp"

char options[2][10] = {"New Game", "Exit"};

void MenuState::renderString(const char* string, float x, float y) const
{
	glDisable(GL_LIGHTING);
	glRasterPos2f(x, y);
	for (unsigned int i = 0; i < strlen(string); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
};

void MenuState::init()
{
	currentChoice = 0;
};

void MenuState::draw() const
{
	glClearColor(0, 0, 1, 1.0);
	for (unsigned int i = 0; i < sizeof(options); i++) {
		glColor3f(1, 1, 1);
		if (i == (unsigned)currentChoice) {
			glColor3f(0, 1, 0);
		}
		renderString(options[i], 100, 50 * (i + 1));
	}
};

void MenuState::update()
{

};

void MenuState::select()
{
	switch (currentChoice)
	{
		case 0:
			break;
		case 1:
			glutDestroyWindow(0);
			break;
	};
};

void MenuState::keyPressed(unsigned char key, int x, int y) 
{
	switch (key)
	{
		// Enter
		case 13:
			select();
			break;
			// Escape
		case 27:
			break;
	};
};

void MenuState::keySpecial(int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_UP:
			currentChoice -= 1;
			if (currentChoice < 0) {
				currentChoice = 0;
			};
			break;
		case GLUT_KEY_DOWN:
			currentChoice += 1;
			if (currentChoice > 1) {
				currentChoice = 0;
			};
			break;
	};
};

