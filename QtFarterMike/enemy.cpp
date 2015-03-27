#include "enemy.h"

Enemy::Enemy()
{
    std::vector<func> StandTasks;
    StandTasks.push_back(&Enemy::InitStand);
    StandTasks.push_back(&Enemy::Stand);
    FStand.AddTasks(StandTasks);

    std::vector<func> WalkTasks;
    WalkTasks.push_back(&Enemy::InitWalk);
    WalkTasks.push_back(&Enemy::Walk);
    FWalk.AddTasks(WalkTasks);

    std::vector<func> PursuitTasks;
    PursuitTasks.push_back(&Enemy::InitPursuit);
    PursuitTasks.push_back(&Enemy::Pursuit);
    FPursuit.AddTasks(PursuitTasks);

    std::vector<func> AttackTasks;
    AttackTasks.push_back(&Enemy::InitAttack);
    AttackTasks.push_back(&Enemy::Attack);
    FAttack.AddTasks(AttackTasks);

    FCurrentSchedule = FWalk;
    FCurrentState = STATE_WALK;

    FActionDelay = 0;
    FThinkInterval = 0;

    FAlert = false;
    FAlertInterval = 0;
}

void Enemy::Think()
{
    GetConditions();
    if (FCurrentSchedule.IsCompleted(FConditions))
    {
        SelectNewSchedule();
    }
}

void Enemy::GetConditions()
{
    FConditions.Clear();

    FConditions.Add(CONDITION_STAND);
    FConditions.Add(CONDITION_WALK);
}

void Enemy::SelectNewSchedule()
{
    switch (FCurrentState) {
    case STATE_STAND:
        if (FConditions.Contains(CONDITION_ATTACK))
        {
            FCurrentSchedule = FAttack;
            FCurrentState = STATE_ATTACK;
        }
        else
        if (FConditions.Contains(CONDITION_ENEMY) && !FConditions.Contains(CONDITION_ATTACK))
        {
            FCurrentSchedule = FPursuit;
            FCurrentState = STATE_PURSUIT;
        }
        else
        if (FConditions.Contains(CONDITION_WALK) && !FConditions.Contains(CONDITION_OBSTACLE))
        {
            FCurrentSchedule = FWalk;
            FCurrentState = STATE_WALK;
        }
        else
        {
            FCurrentSchedule = FStand;
            FCurrentState = STATE_STAND;
        }
        break;
    case STATE_WALK:
        FCurrentSchedule = FWalk;
        FCurrentState = STATE_WALK;
        break;
    case STATE_PURSUIT:
        break;
    case STATE_ATTACK:
        if (FConditions.Contains(CONDITION_ATTACK))
        {
            FCurrentSchedule = FAttack;
            FCurrentState = STATE_ATTACK;
        }
        else
        if (FConditions.Contains(CONDITION_ENEMY) && !FConditions.Contains(CONDITION_ATTACK) && !FConditions.Contains(CONDITION_OBSTACLE))
        {
            FCurrentSchedule = FPursuit;
            FCurrentState = STATE_PURSUIT;
        }
        else
        {
            FCurrentSchedule = FStand;
            FCurrentState = STATE_STAND;
        }
        break;
    default:
        break;
    }
}

bool Enemy::InitStand()
{
    printf("InitStand");

    FActionDelay = rand() % 50 + 25;
    return true;
}

bool Enemy::Stand()
{
    printf("Stand");

    FActionDelay--;
    if (FActionDelay <= 0)
    {
        return true;
    }

    return false;
}

bool Enemy::InitWalk()
{
    printf("InitWalk");

    FActionDelay = rand() % 50 + 25;
    return true;
}

bool Enemy::Walk()
{
    printf("Walk");

    Rect.x += 1;

    FActionDelay--;
    if (FActionDelay <= 0)
    {
        return true;
    }

    return false;
}

bool Enemy::InitPursuit()
{
    printf("InitPursuit");

    FActionDelay = rand() % 50 + 25;
    return true;
}

bool Enemy::Pursuit()
{
    printf("Pursuit");

    FActionDelay--;
    if (FActionDelay <= 0)
    {
        return true;
    }

    return false;
}

bool Enemy::InitAttack()
{
    printf("InitAttack");

    FActionDelay = rand() % 50 + 25;
    return true;
}

bool Enemy::Attack()
{
    printf("Attack");

    FActionDelay--;
    if (FActionDelay <= 0)
    {
        return true;
    }

    return false;
}

void Enemy::Update()
{
    FThinkInterval++;
    if (FThinkInterval > THINK_DELAY)
    {
        Think();
        FThinkInterval = 0;
    }

    if (&FCurrentSchedule != NULL)
    {
        FCurrentSchedule.Update(this);
    }

    if (FAlert)
    {
        FAlertInterval--;
    }
}
