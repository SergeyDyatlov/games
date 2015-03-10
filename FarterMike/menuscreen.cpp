#include "menuscreen.h"

void MenuScreen::init(App& app)
{
	string bgPath = "res/background.bmp";
	string fontPath = "res/font.bmp";
	background.loadFromFile(bgPath);
	font.loadFromFile(fontPath);

	options.push_back("NewGame");
	options.push_back("Exit");
	
	choice = 0;
};

void MenuScreen::draw(App& app)
{
	background.draw(app.surface, 0, 0, 640, 480);
	for (unsigned int i=0; i<options.size(); i++)
	{
		string str = options.at(i);
		int x = (int)((640 / 2) - (font.textWidth(32, str) / 2));
		int offset = 0;
		if ((unsigned)choice == i)
		{
			offset = 5;
		}
		font.drawText(app.surface, x + offset, i * 25, str);
	}
};

void MenuScreen::touch(App& app, int x, int y)
{

};

void MenuScreen::tick(App& app)
{

};

void MenuScreen::active(App& app, bool activated)
{

};
