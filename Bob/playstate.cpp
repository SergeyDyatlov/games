#include "playstate.h"

PlayState PlayState::m_PlayState;

PlayState::PlayState()
{

}

void PlayState::Init()
{
    m_pScreen = NULL;
    printf("PlayState Init Successful\n");
}

void PlayState::Clean()
{
    printf("PlayState Clean Successful\n");
}

void PlayState::Pause()
{
    printf("PlayState Paused Successful\n");
}

void PlayState::Resume()
{
    printf("PlayState Resumed\n");
}

void PlayState::HandleEvents(Game* game)
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
                game -> PushState(PauseState::Instance());
                break;

            default: break;
            }
        }
    }
}

void PlayState::Update(Game* game)
{

}

void PlayState::Draw(Game* game)
{

}
