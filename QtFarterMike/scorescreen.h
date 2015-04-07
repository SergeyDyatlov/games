#ifndef SCORESCREEN_H
#define SCORESCREEN_H

#include "screen.h"
#include "button.h"
#include "scorespritesheet.h"

#include <vector>
#include <string>
#include <sstream>

class ScoreScreen : public Screen
{
private:
    SDL_Texture *FBackground;
    std::vector<std::string> FOptions;
    std::map<int, Button> FButtons;
    ScoreSpriteSheet FScoreSheet;

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
