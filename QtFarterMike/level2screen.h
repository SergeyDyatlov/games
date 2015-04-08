#ifndef LEVEL2SCREEN_H
#define LEVEL2SCREEN_H

#include "playerspritesheet.h"
#include "enemyspritesheet.h"
#include "levelscreen.h"
#include "level1spritesheet.h"
#include <iostream>
#include <fstream>

class Level2Screen : public LevelScreen
{
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
