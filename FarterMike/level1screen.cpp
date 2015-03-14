#include "level1screen.h"

void Level1Screen::init(App& app)
{
	xOffset = 0;
};

void Level1Screen::draw(App& app)
{
	const char*	level[16] = {
		"****************************************",
		"*                                      *",
		"*                                      *",
		"*                                      *",
		"*           $$$                        *",
		"*           ***                        *",
		"*               **                     *",
		"*       ***                     $$     *",
		"*           **     $          ****     *",
		"*              ***    **    $          *",
		"*** $$      **               **        *",
		"*   ***               ***       ***    *",
		"*          ***     $$$    $            *",
		"*      *           ***   **      **    *",
                              *",
		"****************************************",
	};
	for (int col = xOffset / 32 - 1; col < (xOffset + 640) / 40; col++)
		for (int row = 0; row < 480 / 16; row++)
		{
			app.graphicEngine.drawTile(level[col + row * 40], col, row);
		}
};

void Level1Screen::touch(App& app, int x, int y)
{

};

void Level1Screen::tick(App& app)
{

};

void Level1Screen::active(App& app, bool activated)
{

};
