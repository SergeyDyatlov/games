#ifndef MENUSTATE_H
#define MENUSTATE_H

#include <SDL2/SDL.h>
#include "gamestate.h"
#include "playstate.h"
#include "game.h"

class MenuState : public GameState
{
public:
    void Init();
    void Clean();

    void Pause();
    void Resume();

    void HandleEvents(Game* game);
    void Update(Game* game);
    void Draw(Game* game);

    static MenuState* Instance()
    {
        return &m_MenuState;
    }

    SDL_Surface* GetScreen()
    {
        return m_pScreen;
    }

protected:
    MenuState();

private:
    static MenuState m_MenuState;
    SDL_Surface* m_pScreen;
};

#endif // MENUSTATE_H
