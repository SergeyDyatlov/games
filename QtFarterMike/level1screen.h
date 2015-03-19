#ifndef LEVEL1SCREEN_H
#define LEVEL1SCREEN_H

#include "screen.h"
#include "level1spritesheet.h"
#include "hero.h"
#include "enemy.h"
#include <string>
#include <vector>

class Level1Screen : public Screen
{
private:
    std::string FMap[16];
    int FMapHeight;
    int FMapWidth;
    std::vector<Enemy> FEnemies;

    SDL_Rect FBgRect;

    Level1SpriteSheet FSpriteSheet;

    Hero FHero;

    float FOffsetX;

public:
    Level1Screen();
    ~Level1Screen();
    void Init(Game& AGame);
    void Clean();

    void HandleEvents(Game& AGame);
    void Update(Game& AGame);
    void Draw(Game& AGame);
};

#endif // LEVEL1SCREEN_H
