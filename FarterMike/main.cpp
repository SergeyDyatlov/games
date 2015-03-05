#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

using namespace std;

SDL_Window* window;

const int width = 640;
const int height = 480;

void init()
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	SDL_GLContext glcontext = SDL_GL_CreateContext(window);

	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, height, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}

void loop()
{

}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	glBegin(GL_QUADS);
	glVertex2f(0, 0);
	glVertex2f(100, 0);
	glVertex2f(100, 100);
	glVertex2f(0, 100);
	glEnd;
	
	glFlush();
	SDL_GL_SwapWindow(window);
}

int main(int argc, char **argv)
{
	init();
	bool isRunning = true;
	SDL_Event event;
	while (isRunning){
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_QUIT:
					isRunning = false;
					break;
			}
		}
		loop();
		draw();
	}
	SDL_Quit();
	return 0;
}
