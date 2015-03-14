#include "pausestate.h"

PauseState PauseState::m_PauseState;

PauseState::PauseState()
{
}

void PauseState::Init()
{
    m_pScreen = NULL;
    printf("PauseState Init Successful\n");
}

void PauseState::Clean()
{
    printf("PauseState Clean Successful\n");
}

void PauseState::Pause()
{
    printf("PauseState Paused Successful\n");
}

void PauseState::Resume()
{
    printf("PauseState Resumed\n");
}

void PauseState::HandleEvents(Game* game)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            game -> Quit();
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_SPACE:
                game -> PopState();
                break;

            default: break;
            }
        }
    }
}

void PauseState::Update(Game* game)
{

}

void PauseState::Draw(Game* game)
{

}
