#ifndef GAME_H
#define GAME_H

#include "screen.h"
#include "menuscreen.h"
#include "selectlevelscreen.h"
#include "level1screen.h"
#include "level2screen.h"
#include <SDL2/SDL.h>
#include <vector>
#include <string>

class Game
{
private:
    bool FRunning;
    SDL_Window* FWindow;
    SDL_Renderer* FRenderer;
    SDL_Surface* FSurface;
    std::vector<Screen*> FScreens;

    MenuScreen FMenuScreen;
    SelectLevelScreen FSelectLevelScreen;

    Level1Screen FLevel1Screen;
    Level2Screen FLevel2Screen;

public:
    Game();
    enum ScreenType {stMenu, stSelectLevelScreen, stLevel1, stLevel2};
    ScreenType FCurrentScreen;

    void Init(const char* Caption, int Width, int Height);

    void SetScreen(ScreenType screen);

    void HandleEvents();
    void Update();
    void Draw();

    void Quit();

    void Clean();

    SDL_Surface* GetSurface()
    {
        return FSurface;
    }

    bool IsRunning()
    {
        return FRunning;
    }
};

#endif // GAME_H
