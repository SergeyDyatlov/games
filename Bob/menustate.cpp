#include "menustate.h"

MenuState MenuState::m_MenuState;

MenuState::MenuState()
{

}

void MenuState::Init()
{
    m_pScreen = NULL;
    printf("MenuState Init Successful\n");
}

void MenuState::Clean()
{
    printf("MenuState Clean Successful\n");
}

void MenuState::Pause()
{
    printf("MenuState Paused\n");
}

void MenuState::Resume()
{
    printf("MenuState Resumed\n");
}

void MenuState::HandleEvents(Game *game)
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
                game -> ChangeState(PlayState::Instance());
                break;

            default:
                break;
            }
        }
    }
}

void MenuState::Update(Game *game)
{

}

void MenuState::Draw(Game *game)
{

}
