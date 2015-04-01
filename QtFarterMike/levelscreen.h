#ifndef LEVELSCREEN_H
#define LEVELSCREEN_H

#include "screen.h"
#include "hero.h"
#include "enemy.h"
#include "sprite.h"
#include <string>
#include <vector>

struct TScores {
    int Coins;
    int Killed;
};

const int TILE_SIZE = 24;

class LevelScreen : public Screen
{
public:
    LevelScreen();
    ~LevelScreen();
    virtual void Init(Game& AGame);
    virtual void Clean();

    virtual void HandleEvents(Game& AGame);
    virtual void Update(Game& AGame);
    virtual void Draw(Game& AGame);

    std::string Map[14];
    int MapWidth;
    int MapHeight;

    float OffsetX;

    std::vector<Enemy> Enemies;
    Hero Player;

    std::vector<Sprite> Coins;
};

#endif // LEVELSCREEN_H
