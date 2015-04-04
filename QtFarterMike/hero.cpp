#include "hero.h"
#include "levelscreen.h"

Hero::Hero()
{
    FHealth = 100;
    FDead = false;

    StartFrame = 1;
    EndFrame = 2;
    Frame = 0;

    Direction = 1;
    Action = paStand;
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
    Fvx = -20.0f;
    Direction = 0;
    StartFrame = 0;
    EndFrame = 6;
    Action = paMoveLeft;
}

void Hero::Right()
{
    Fvx = 20.0f;
    Direction = 1;
    StartFrame = 0;
    EndFrame = 6;
    Action = paMoveRight;
}

void Hero::Stop()
{
    Fvx = 0;
    switch (Direction) {
    case 0:
        StartFrame = 1;
        EndFrame = 2;
        break;
    case 1:
        StartFrame = 0;
        EndFrame = 1;
        break;
    default:
        break;
    }
    Action = paStand;
}

void Hero::Jump()
{
    if (!FDidJump && HasCollision(Fx, Fy + 4))
    {
        Fvy -= 30.0f;
        FDidJump = true;
    }
}

bool Hero::HasCollision(float x, float y) const
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


void Hero::Update()
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
