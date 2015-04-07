#ifndef FONT_H
#define FONT_H

#include <SDL2/SDL.h>
#include <string>

class TFont
{
private:
    SDL_Texture *FTexture;

public:
    TFont();
    int Height;
    void LoadFromFile(SDL_Renderer *ARenderer, const std::string &path);
    void DrawChar(SDL_Renderer *ARenderer, int X, int Y, int asciicode);
    void DrawText(SDL_Renderer *ARenderer, int X, int Y, const std::string &text);
    int TextWidth(const std::string &text);
};

#endif // FONT_H
