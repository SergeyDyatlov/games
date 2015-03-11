#include "menuscreen.h"
#include "getresourcepath.h"

void MenuScreen::init(App& app)
{
	string fontPath = getResourcePath() + "/font.bmp";
	font.loadFromFile(fontPath);

	options.push_back("NewGame");
	options.push_back("Exit");
	
	choice = 0;
};

void MenuScreen::draw(App& app)
{
	for (unsigned int i=0; i<options.size(); i++)
	{
		string str = options.at(i);
		int x = (int)((640 / 2) - (font.textWidth(32, str) / 2));
		int offset = 0;
		if ((unsigned)choice == i)
		{
			offset = 5;
		}
		font.drawText(app.graphicEngine.surface, x + offset, i * 25, str);
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
