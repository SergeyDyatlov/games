#include "movable.h"
#include "levelscreen.h"

Movable::Movable()
{
}

void Movable::SetRect(const SDL_Rect &rect)
{
    FRect = rect;
    Fx = FRect.x;
    Fy = FRect.y;
}

const SDL_Rect &Movable::GetRect() const
{
    return FRect;
}

void Movable::MoveLeft()
{
    Fvx = -15.0f;
}

void Movable::MoveRight()
{
    Fvx = 15.0f;
}

bool Movable::HasCollision(float x, float y) const
{
    for (int row = y / TILE_SIZE; row <= (y + FRect.h) / TILE_SIZE; ++row)
    {
        if (row < 0 || row >= static_cast<int>(sizeof(Level->Map) / sizeof(*Level->Map)))
            return true;
        for (int col = x / TILE_SIZE; col <= (x + FRect.w) / TILE_SIZE; ++col)
        {
            if (col < 0 || col >= static_cast<int>(Level->Map[row].size()))
                return true;
            char ch = Level->Map[row][col];
            switch (ch)
            {
            case '#':
            case '|':
            case '*':
                return true;
            default:
                break;
            }
        }
    }
    return false;
}

void Movable::CheckCollision()
{
    auto Dt = 1.0f / 5.0f;
    auto x = Fx + Fvx * Dt;
    if (HasCollision(x, Fy))
    {
        x = Fx;
    }
    auto y = Fy + Fvy * Dt;
    Fvy += 9.81 * Dt;

    if (!HasCollision(x, y))
    {
        Fy = y;
        FRect.y = Fy;
    }
    else
    {
        Fvy = 0.0f;
        FDidJump = false;
    }
    Fx = x;
    FRect.x = Fx;
}
