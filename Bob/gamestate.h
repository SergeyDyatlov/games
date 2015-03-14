#ifndef GAMESTATE_H
#define GAMESTATE_H

class Game;

class GameState
{
public:
    virtual void Init() = 0;
    virtual void Clean() = 0;

    virtual void Pause() = 0;
    virtual void Resume() = 0;

    virtual void HandleEvents(Game* game) = 0;
    virtual void Update(Game* game) = 0;
    virtual void Draw(Game* game) = 0;

protected:
    GameState(){}
};

#endif // GAMESTATE_H
