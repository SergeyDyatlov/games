#include "menuscreen.h"
#include "app.h"

void MenuScreen::init(App& app)
{
	background = IMG_LoadTexture(app.renderer, "res/background.png");
};

void MenuScreen::draw(App& app) const
{
	SDL_RenderCopy(app.renderer, background, NULL, NULL);
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
