#ifndef SELECTLEVELSCREEN_H
#define SELECTLEVELSCREEN_H

#include "screen.h"
#include "button.h"
#include <vector>
#include <string>
#include <map>

class SelectLevelScreen : public Screen
{
private:
    std::vector<std::string> FOptions;
    std::map<int, Button> FButtons;

public:
    SelectLevelScreen();
    ~SelectLevelScreen();
    void Init(Game& AGame);
    void Clean();

    void HandleEvents(Game& AGame);
    void Update(Game& AGame);
    void Draw(Game& AGame);
};

#endif // SELECTLEVELSCREEN_H
