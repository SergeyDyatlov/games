#include "hero.h"
#include "levelscreen.h"

Hero::Hero()
{
    FHealth = 100;
    FDead = false;
}

void Hero::Hit()
{
    FHealth -= 1;

    if (FHealth <= 0)
    {
        FDead = true;
    }

    printf("Hero Attacked: %d\n", FHealth);
}

bool Hero::IsDead()
{
    return FDead;
}

void Hero::Left()
{
    Fvx = -10.0f;
}

void Hero::Right()
{
    Fvx = 10.0f;
}

void Hero::Stop()
{
    Fvx = 0;
}

void Hero::Jump()
{
    if (!FDidJump)
    {
        Fvy -= 20.0f;
        FDidJump = true;
    }
}

void Hero::Update()
{
    auto Dt = 1.0f / 5.0f;
    auto x = Fx + Fvx * Dt;
    auto y = Fy + Fvy * Dt;
    Fvy += 9.81 * Dt;
    bool hasCollision = false;
    for (int row = y / TILE_SIZE; row <= (y + FRect.h) / TILE_SIZE; ++row)
    {
        if (row < 0 || row >= static_cast<int>(sizeof(Level->Map) / sizeof(*Level->Map)))
        {
            hasCollision = true;
            break;
        }
        for (int col = x / TILE_SIZE; col <= (x + FRect.w) / TILE_SIZE; ++col)
        {
            if (col < 0 || col >= static_cast<int>(Level->Map[row].size()))
            {
                hasCollision = true;
                break;
            }
            char ch = Level->Map[row][col];
            switch (ch)
            {
            case '#':
            case '|':
            case '*':
                hasCollision = true;
                break;
            default:
                break;
            }
            if (hasCollision)
                break;
        }
        if (hasCollision)
            break;
    }
    if (!hasCollision)
    {
        Fx = x;
        Fy = y;
        FRect.x = Fx;
        FRect.y = Fy;
    }
    else
    {
        Fvy = -0.5f * Fvy;
        FDidJump = false;
    }
}

void Hero::SetRect(const SDL_Rect &rect)
{
    FRect = rect;
    Fx = FRect.x;
    Fy = FRect.y;
}

const SDL_Rect &Hero::GetRect() const
{
    return FRect;
}
