#ifndef LEVEL1SCREEN_H
#define LEVEL1SCREEN_H

#include "levelscreen.h"
#include "level1spritesheet.h"

class Level1Screen : public LevelScreen
{
private:
    SDL_Rect FBgRect;
    Level1SpriteSheet FSpriteSheet;

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
