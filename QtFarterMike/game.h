#ifndef GAME_H
#define GAME_H

#include "screen.h"
#include "menuscreen.h"
#include "selectlevelscreen.h"
#include "scorescreen.h"
#include "level1screen.h"
#include "level2screen.h"
#include "font.h"
#include <SDL2/SDL.h>
#include <vector>
#include <string>

class Game
{
private:
    bool FRunning;
    SDL_Window* FWindow;
    SDL_Renderer* FRenderer;

    MenuScreen FMenuScreen;
    SelectLevelScreen FLevelSelectionScreen;
    ScoreScreen FScoreScreen;

    Level1Screen FLevel1Screen;
    Level2Screen FLevel2Screen;

public:
    Game();

    Screen* CurrentScreen;
    int CurrentLevel;
    TScores Scores;

    TFont Font;

    void Init(const char* Caption, int Width, int Height);

    void SetMenuScreen();
    void SetLevelSelectionScreen();
    void SetScoreScreen();
    void SetLevelScreen(int Level);

    void HandleEvents();
    void Update();
    void Draw();

    void Quit();

    void Clean();

    SDL_Window* GetWindow()
    {
        return FWindow;
    }

    SDL_Renderer* GetRenderer()
    {
        return FRenderer;
    }

    bool IsRunning()
    {
        return FRunning;
    }
};

#endif // GAME_H
