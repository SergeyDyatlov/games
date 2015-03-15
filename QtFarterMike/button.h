#ifndef BUTTON_H
#define BUTTON_H

#include <SDL2/SDL.h>

class Button
{
public:
    Button();
    Button(int X, int Y, int Width, int Height);
    void Draw(SDL_Surface* ASurface);
    SDL_Rect Box;
    bool Clicked;
};

#endif // BUTTON_H
