#ifndef SCORESPRITESHEET_H
#define SCORESPRITESHEET_H

#include <SDL2/SDL.h>
#include <string>
#include <map>

enum ScoreSpriteType {stMenu, stRestart, stNext};

class ScoreSpriteSheet
{
private:
    std::map<ScoreSpriteType, SDL_Rect> FSprites;
    SDL_Surface* FSurface;

public:
    ScoreSpriteSheet();
    void Draw(SDL_Surface* Surface, ScoreSpriteType Type, SDL_Rect* Rect);
};

#endif // SCORESPRITESHEET_H
