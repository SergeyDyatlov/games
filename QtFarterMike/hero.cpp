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
