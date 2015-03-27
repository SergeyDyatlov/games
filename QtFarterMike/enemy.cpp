#include "enemy.h"
#include "hero.h"

Enemy::Enemy()
{
    std::vector<func> StandTasks;
    StandTasks.push_back(&Enemy::InitStand);
    StandTasks.push_back(&Enemy::Stand);
    FStand.Type = SCHEDULE_STAND;
    FStand.AddTasks(StandTasks);
    std::vector<int> StandConditions;
    StandConditions.push_back(CONDITION_ENEMY);
    StandConditions.push_back(CONDITION_ATTACK);
    FPursuit.AddInterrupts(StandConditions);

    std::vector<func> WalkTasks;
    WalkTasks.push_back(&Enemy::InitWalk);
    WalkTasks.push_back(&Enemy::Walk);
    FWalk.Type = SCHEDULE_WALK;
    FWalk.AddTasks(WalkTasks);
    std::vector<int> WalkConditions;
    WalkConditions.push_back(CONDITION_OBSTACLE);
    WalkConditions.push_back(CONDITION_ATTACK);
    WalkConditions.push_back(CONDITION_ENEMY);
    FPursuit.AddInterrupts(WalkConditions);

    std::vector<func> PursuitTasks;
    PursuitTasks.push_back(&Enemy::InitPursuit);
    PursuitTasks.push_back(&Enemy::Pursuit);
    FPursuit.Type = SCHEDULE_PURSUIT;
    FPursuit.AddTasks(PursuitTasks);
    std::vector<int> PersuitConditions;
    PersuitConditions.push_back(CONDITION_OBSTACLE);
    PersuitConditions.push_back(CONDITION_ATTACK);
    FPursuit.AddInterrupts(PersuitConditions);

    std::vector<func> AttackTasks;
    AttackTasks.push_back(&Enemy::InitAttack);
    AttackTasks.push_back(&Enemy::Attack);
    FAttack.Type = SCHEDULE_ATTACK;
    FAttack.AddTasks(AttackTasks);

    FSchedules.push_back(FStand);
    FSchedules.push_back(FWalk);
    FSchedules.push_back(FPursuit);
    FSchedules.push_back(FAttack);

    SetSchedule(SCHEDULE_STAND);

    FActionDelay = 0;
    FThinkInterval = 0;

    FAlert = false;
    FAlertInterval = 0;

    FTarget = NULL;
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
            SetSchedule(SCHEDULE_ATTACK);
        } else if (FConditions.Contains(CONDITION_ENEMY) && !FConditions.Contains(CONDITION_ATTACK))
        {
            SetSchedule(SCHEDULE_PURSUIT);
        } else if (FConditions.Contains(CONDITION_WALK) && !FConditions.Contains(CONDITION_OBSTACLE))
        {
            SetSchedule(SCHEDULE_WALK);
        } else
        {
            SetSchedule(SCHEDULE_STAND);
        }
        break;
    case STATE_WALK:
        SetSchedule(SCHEDULE_WALK);
        break;
    case STATE_PURSUIT:
        SetSchedule(SCHEDULE_PURSUIT);
        break;
    case STATE_ATTACK:
        if (FConditions.Contains(CONDITION_ATTACK))
        {
            SetSchedule(SCHEDULE_ATTACK);
        } else if (FConditions.Contains(CONDITION_ENEMY) && !FConditions.Contains(CONDITION_ATTACK) && !FConditions.Contains(CONDITION_OBSTACLE))
        {
            SetSchedule(SCHEDULE_PURSUIT);
        } else
        {
            SetSchedule(SCHEDULE_STAND);
        }
        break;
    default:
        break;
    }
}

void Enemy::SetSchedule(int ASchedule)
{
    for (std::vector<Schedule>::iterator item = FSchedules.begin(); item != FSchedules.end(); item++)
    {
        Schedule schedule = *item;
        if (schedule.Type == ASchedule)
        {
            FCurrentSchedule = schedule;
            FCurrentSchedule.Reset();
        }
    }

    switch (ASchedule) {
    case SCHEDULE_STAND:
        FCurrentState = STATE_STAND;
        break;
    case SCHEDULE_WALK:
        FCurrentState = STATE_WALK;
        break;
    case SCHEDULE_PURSUIT:
        FCurrentState = STATE_PURSUIT;
        break;
    case SCHEDULE_ATTACK:
        FCurrentState = STATE_ATTACK;
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

    return true;
}

bool Enemy::Attack()
{
    printf("Attack");

    if (FTarget != NULL)
    {
        FTarget->Hit();

        if (FTarget->IsDead())
        {
            FTarget = NULL;
            FAlert = false;
            FAlertInterval = 0;
        }
    }

    return true;
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
