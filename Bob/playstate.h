#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include <SDL2/SDL.h>
#include "gamestate.h"
#include "menustate.h"
#include "pausestate.h"
#include "game.h"

class PlayState : public GameState
{
public:
    void Init();
    void Clean();

    void Pause();
    void Resume();

    void HandleEvents(Game* game);
    void Update(Game* game);
    void Draw(Game* game);

    static PlayState* Instance()
    {
        return &m_PlayState;
    }

    SDL_Surface* GetScreen()
    {
        return m_pScreen;
    }

protected:
    PlayState();

private:
    static PlayState m_PlayState;
    SDL_Surface* m_pScreen;
};

#endif // PLAYSTATE_H
