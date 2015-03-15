#include "button.h"

Button::Button(int X, int Y, int Width, int Height)
{
    Box.x = X;
    Box.y = Y;
    Box.w = Width;
    Box.h = Height;
}

void Button::Draw(SDL_Surface* ASurface)
{
    SDL_FillRect(ASurface, &Box, SDL_MapRGB(ASurface -> format, 0, 255, 0));
}
