#ifndef ENEMY_H
#define ENEMY_H

#include "schedule.h"
#include <SDL2/SDL.h>
#include <vector>

const int THINK_DELAY = 50;

const int STATE_STAND = 0;
const int STATE_WALK = 1;
const int STATE_PURSUIT = 2;
const int STATE_ATTACK = 3;

const int CONDITION_STAND = 0;
const int CONDITION_WALK = 1;
const int CONDITION_ENEMY = 2;
const int CONDITION_ATTACK = 3;
const int CONDITION_OBSTACLE = 4;

class Enemy
{
private:
    Schedule FStand;
    Schedule FWalk;
    Schedule FPursuit;
    Schedule FAttack;
    Schedule FCurrentSchedule;
    std::vector<Schedule> FSchedules;

    ConditionList FConditions;

    int FCurrentState;

    int FThinkInterval;
    int FActionDelay;

    bool FAlert;
    int FAlertInterval;

    void Think();
    void GetConditions();
    void SelectNewSchedule();

    bool InitStand();
    bool Stand();
    bool InitWalk();
    bool Walk();
    bool InitPursuit();
    bool Pursuit();
    bool InitAttack();
    bool Attack();

public:
    Enemy();
    void Update();

    SDL_Rect Rect;
};

#endif // ENEMY_H
