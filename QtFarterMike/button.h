#ifndef BUTTON_H
#define BUTTON_H

#include <SDL2/SDL.h>

class Button
{
public:
    Button(int X = 0, int Y = 0, int Width = 0, int Height = 0);
    void Draw(SDL_Surface* ASurface);
    SDL_Rect Box;
    bool Clicked;
};

#endif // BUTTON_H
