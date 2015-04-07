#include "game.h"

Game::Game()
{
    CurrentLevel = 0;
}

void Game::Init(const char* Caption, int Width, int Height)
{
    SDL_Init(SDL_INIT_VIDEO);
    FWindow = SDL_CreateWindow(
                Caption,
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                Width,
                Height,
                SDL_WINDOW_SHOWN);
    FRenderer = SDL_CreateRenderer(FWindow, -1, SDL_RENDERER_SOFTWARE);

    Font.LoadFromFile(FRenderer, "res/font.bmp");

    FRunning = true;

    SetMenuScreen();

    printf("Game Init Successful\n");
}

void Game::SetMenuScreen()
{
    CurrentScreen = &FMenuScreen;
    CurrentScreen->Init(*this);
}

void Game::SetScoreScreen()
{
    CurrentScreen = &FScoreScreen;
    CurrentScreen->Init(*this);
}

void Game::SetLevelSelectionScreen()
{
    CurrentScreen = &FLevelSelectionScreen;
    CurrentScreen->Init(*this);
}

void Game::SetLevelScreen(int Level)
{
    switch (Level) {
    case 1:
        CurrentLevel = Level;
        CurrentScreen = &FLevel1Screen;
        CurrentScreen->Init(*this);
        break;
    case 2:
        CurrentLevel = Level;
        CurrentScreen = &FLevel2Screen;
        CurrentScreen->Init(*this);
        break;
    default:
        break;
    }
}

void Game::HandleEvents()
{
    CurrentScreen->HandleEvents(*this);
}

void Game::Update()
{
    CurrentScreen->Update(*this);
}

void Game::Draw()
{
    SDL_RenderClear(FRenderer);

    CurrentScreen->Draw(*this);

    SDL_RenderPresent(FRenderer);
    SDL_Delay(30);
}

void Game::Quit()
{
    FRunning = false;
}

void Game::Clean()
{
    SDL_DestroyRenderer(FRenderer);
    SDL_DestroyWindow(FWindow);
    SDL_Quit();

    printf("Game Clean Successful\n");
}
