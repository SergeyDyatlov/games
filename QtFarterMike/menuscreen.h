#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include "screen.h"
#include "button.h"
#include "menuspritesheet.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <string>
#include <map>

class MenuScreen : public Screen
{
private:
    SDL_Texture* FBackground;
    std::vector<std::string> FOptions;
    std::map<int, Button> FButtons;
    MenuSpriteSheet FSpriteSheet;

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
