#ifndef LEVEL1SCREEN_H
#define LEVEL1SCREEN_H

#include "screen.h"
#include "level1spritesheet.h"
#include <string>

class Level1Screen : public Screen
{
private:
    std::string FMap[16];
    int FMapHeight;
    int FMapWidth;

    SDL_Rect FBgRect;

    Level1SpriteSheet FSpriteSheet;

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
