#include "game.h"

Game::Game()
{
}

void Game::Init(const char* title, int width, int height)
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(
                title,
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                width,
                height,
                SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    m_pScreen = SDL_CreateRGBSurface(0, 640, 480, 32, 0, 0, 0, 0);
    m_bRunning = true;
}

void Game::ChangeState(GameState *state)
{
    if (!states.empty())
    {
        states.back() -> Clean();
        states.pop_back();
    }

    states.push_back(state);
    states.back() -> Init();
}

void Game::PushState(GameState *state)
{
    if (!states.empty())
    {
        states.back() -> Pause();
    }

    states.push_back(state);
    states.back() -> Init();
}

void Game::PopState()
{
    if (!states.empty())
    {
        states.back() -> Clean();
        states.pop_back();
    }

    if (!states.empty())
    {
        states.back() -> Resume();
    }
}

void Game::HandleEvents()
{
    states.back() -> HandleEvents(this);
}

void Game::Update()
{
    states.back() -> Update(this);
}

void Game::Draw()
{
    states.back() -> Draw(this);
}

void Game::Clean()
{
    while (!states.empty())
    {
        states.back() -> Clean();
        states.pop_back();
    }
    SDL_FreeSurface(m_pScreen);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
