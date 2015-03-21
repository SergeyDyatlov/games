#ifndef SCORESCREEN_H
#define SCORESCREEN_H

#include "screen.h"
#include "button.h"
#include "scorespritesheet.h"
#include <vector>
#include <string>

class ScoreScreen : public Screen
{
private:
    std::vector<std::string> FOptions;
    std::map<int, Button> FButtons;
    ScoreSpriteSheet FSpriteSheet;

public:
    ScoreScreen();
    ~ScoreScreen();
    void Init(Game& AGame);
    void Clean();

    void HandleEvents(Game& AGame);
    void Update(Game& AGame);
    void Draw(Game& AGame);
};

#endif // SCORESCREEN_H
