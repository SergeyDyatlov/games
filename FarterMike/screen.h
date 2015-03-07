#pragma once

class App;

using namespace std;

class Screen
{
	public:
		virtual void init(App& app) = 0;
		virtual void draw(App& app) = 0;
		virtual void touch(App& app, int x, int y) = 0;
		virtual void tick(App& app) = 0;
		virtual void active(App& app, bool activated) = 0;
};
