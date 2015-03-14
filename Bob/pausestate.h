#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include <SDL2/SDL.h>
#include "gamestate.h"
#include "playstate.h"
#include "game.h"

class PauseState : public GameState
{
public:
    void Init();
    void Clean();

    void Pause();
    void Resume();

    void HandleEvents(Game* game);
    void Update(Game* game);
    void Draw(Game* game);

    static PauseState* Instance()
    {
        return &m_PauseState;
    }

    SDL_Surface* GetScreen()
    {
        return m_pScreen;
    }

protected:
    PauseState();

private:
    static PauseState m_PauseState;
    SDL_Surface* m_pScreen;
};

#endif // PAUSESTATE_H
