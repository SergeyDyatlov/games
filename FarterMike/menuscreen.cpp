#include "menuscreen.h"
#include "app.h"

void MenuScreen::init(App& app)
{
	background.loadFromFile(app.renderer, "res/background.png");
};

void MenuScreen::draw(App& app) const
{
	background.render(app.renderer, NULL, NULL);
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
