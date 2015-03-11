#pragma once

class Tile {
	public:
		int x;
		int y;
		int w;
		int h;
		int frames;
		Tile(int X = 0, int Y = 0, int W = 0, int H = 0, int Frames = 0)
		{
			x = X;
			y = Y;
			w = W;
			h = H;
			frames = Frames;
		}
};
