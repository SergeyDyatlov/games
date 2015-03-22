#ifndef FONT_H
#define FONT_H

#include <SDL2/SDL.h>
#include <string>

class TFont
{
private:
    SDL_Surface* FBitmap;

public:
    TFont();
    int Height;
    void LoadFromFile(const std::string &path);
    void DrawChar(SDL_Surface* Surface, int X, int Y, int asciicode);
    void DrawText(SDL_Surface* Surface, int X, int Y, const std::string &text);
    int TextWidth(const std::string &text);
};

#endif // FONT_H
