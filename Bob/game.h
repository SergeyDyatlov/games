#ifndef GAME_H
#define GAME_H

#include "gamestate.h"
#include <SDL2/SDL.h>
#include <vector>

class Game
{
public:
    Game();
    void Init(const char* title, int width, int height);

    void ChangeState(GameState* state);
    void PushState(GameState* state);
    void PopState();

    void HandleEvents();
    void Update();
    void Draw();
    void Clean();

    bool IsRunning()
    {
        return m_bRunning;
    }
    void Quit()
    {
        m_bRunning = false;
    }
private:
    std::vector<GameState*> states;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Surface* m_pScreen;
    bool m_bRunning;
};

#endif // GAME_H
