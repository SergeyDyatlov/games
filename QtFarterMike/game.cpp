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
    FSurface = SDL_CreateRGBSurface(0, Width, Height, 32, 0, 0, 0, 0);

    FScreens.push_back(&FMenuScreen);
    FScreens.push_back(&FSelectLevelScreen);
    FScreens.push_back(&FScoreScreen);

    FScreens.push_back(&FLevel1Screen);
    FScreens.push_back(&FLevel2Screen);
    SetScreen(stMenu);

    FRunning = true;

    printf("Game Init Successful\n");
}

void Game::SetScreen(ScreenType AScreenType)
{
    FCurrentScreen = AScreenType;
    FScreens.at(FCurrentScreen) -> Init(*this);
}

void Game::SetLevel(int LevelNum)
{

}

void Game::RestartLevel()
{
    SetLevel(CurrentLevel);
}

void Game::NextLevel()
{
    CurrentLevel += 1;
    SetLevel(CurrentLevel);
}

void Game::HandleEvents()
{
    FScreens.at(FCurrentScreen) -> HandleEvents(*this);
}

void Game::Update()
{
    FScreens.at(FCurrentScreen) -> Update(*this);
}

void Game::Draw()
{
    SDL_RenderClear(FRenderer);
    SDL_FillRect(FSurface, NULL, SDL_MapRGB(FSurface -> format, 255, 255, 255));

    FScreens.at(FCurrentScreen) -> Draw(*this);

    SDL_Texture* Texture = SDL_CreateTextureFromSurface(FRenderer, FSurface);
    SDL_RenderCopy(FRenderer, Texture, NULL, NULL);
    SDL_DestroyTexture(Texture);
    SDL_RenderPresent(FRenderer);
    SDL_Delay(30);
}

void Game::Quit()
{
    FRunning = false;
}

void Game::Clean()
{
    while (!FScreens.empty())
    {
        FScreens.back() -> Clean();
        FScreens.pop_back();
    }
    SDL_FreeSurface(FSurface);
    SDL_DestroyRenderer(FRenderer);
    SDL_DestroyWindow(FWindow);
    SDL_Quit();

    printf("Game Clean Successful\n");
}
