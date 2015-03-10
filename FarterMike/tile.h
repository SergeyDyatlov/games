#pragma once

class Tile {
	public:
		int x;
		int y;
		int w;
		int h;
		int frames;
		Tile(int x, int y, int w, int h, int frames)
		{
			x = x;
			y = y;
			w = w;
			h = h;
			frames = frames;
		}
};
