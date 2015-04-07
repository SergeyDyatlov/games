#include "button.h"

Button::Button(int X, int Y, int Width, int Height)
{
    Rect.x = X;
    Rect.y = Y;
    Rect.w = Width;
    Rect.h = Height;
}

void Button::Draw(SDL_Renderer* ARenderer)
{
//    SDL_FillRect(ASurface, &Rect, SDL_MapRGB(ASurface -> format, 0, 255, 0));
}
