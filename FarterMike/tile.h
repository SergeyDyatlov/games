#pragma once

class Tile {
	public:
		int x;
		int y;
		int w;
		int h;
		int frames;
		Tile(int x = 0, int y = 0, int w = 0, int h = 0, int frames = 0)
		{
			x = x;
			y = y;
			w = w;
			h = h;
			frames = frames;
		}
};
