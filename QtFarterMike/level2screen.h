#ifndef LEVEL2SCREEN_H
#define LEVEL2SCREEN_H

#include "levelscreen.h"
#include "level1spritesheet.h"

class Level2Screen : public LevelScreen
{
private:
    SDL_Rect FBgRect;
    Level1SpriteSheet FSpriteSheet;

public:
    Level2Screen();
    ~Level2Screen();
    void Init(Game& AGame);
    void Clean();

    void HandleEvents(Game& AGame);
    void Update(Game& AGame);
    void Draw(Game& AGame);
};

#endif // LEVEL2SCREEN_H
