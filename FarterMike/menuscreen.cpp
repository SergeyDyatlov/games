#include "menuscreen.h"
#include "getresourcepath.h"

void MenuScreen::init(App& app)
{
	string fontPath = getResourcePath() + "/font.bmp";
	font.loadFromFile(fontPath);

	string spritePath = getResourcePath() + "/background.bmp";
	spriteSheet.loadFromFile(spritePath);

	options.push_back("New Game");
	options.push_back("Exit");

	for (unsigned i=0; i<options.size(); i++)
	{
		int width = font.textWidth(24, options[i]);
		int x = ((640 / 2) - (width) / 2);
		buttons[i] = Button(x, i * 50, width, 20);
	}
};

void MenuScreen::draw(App& app)
{
	spriteSheet.draw(app.graphicEngine.surface, Background, 0, 0, 0);

	for (unsigned i=0; i<options.size(); i++)
	{
		buttons[i].draw(app.graphicEngine.surface);
		font.drawText(app.graphicEngine.surface, buttons[i].box.x, buttons[i].box.y, options[i]);
	}
};

void MenuScreen::touch(App& app, int x, int y)
{	
	for (unsigned i=0; i<options.size(); i++)
	{
		buttons[i].clicked = false;
		if ((x > buttons[i].box.x) && (x < buttons[i].box.x + buttons[i].box.w))
			if ((y > buttons[i].box.y) && (y < buttons[i].box.y + buttons[i].box.h))
			{
				buttons[i].clicked = true;
			}
	}
};

void MenuScreen::tick(App& app)
{
	if (buttons[0].clicked == true)
	{
		app.setScreen(app.stLevel1);
	}
};

void MenuScreen::active(App& app, bool activated)
{

};
