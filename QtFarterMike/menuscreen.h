#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include "screen.h"
#include "game.h"
#include <button.h>
#include <vector>
#include <string>
#include <map>

class MenuScreen : public Screen
{
private:
    std::vector<std::string> Options;
    std::map<int, Button> Buttons;

public:
    MenuScreen();
    ~MenuScreen();
    void Init(Game& AGame);
    void Clean();

    void HandleEvents(Game& AGame);
    void Update(Game& AGame);
    void Draw(Game& AGame);
};

#endif // MENUSCREEN_H
