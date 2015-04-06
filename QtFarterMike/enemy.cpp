#include "enemy.h"
#include "hero.h"
#include "levelscreen.h"

Enemy::Enemy()
{
    std::vector<func> StandTasks;
    StandTasks.push_back(&Enemy::InitStand);
    StandTasks.push_back(&Enemy::Stand);
    FStand.Type = SCHEDULE_STAND;
    FStand.AddTasks(StandTasks);
    std::vector<int> StandConditions;
    StandConditions.push_back(CONDITION_SEE_ENEMY);
    StandConditions.push_back(CONDITION_CAN_ATTACK);
    FStand.AddInterrupts(StandConditions);

    std::vector<func> WalkTasks;
    WalkTasks.push_back(&Enemy::InitWalk);
    WalkTasks.push_back(&Enemy::Walk);
    FWalk.Type = SCHEDULE_WALK;
    FWalk.AddTasks(WalkTasks);
    std::vector<int> WalkConditions;
    WalkConditions.push_back(CONDITION_OBSTACLE);
    WalkConditions.push_back(CONDITION_CAN_ATTACK);
    WalkConditions.push_back(CONDITION_SEE_ENEMY);
    FWalk.AddInterrupts(WalkConditions);

    std::vector<func> PursuitTasks;
    PursuitTasks.push_back(&Enemy::InitPursuit);
    PursuitTasks.push_back(&Enemy::Pursuit);
    FPursuit.Type = SCHEDULE_PURSUIT;
    FPursuit.AddTasks(PursuitTasks);
    std::vector<int> PersuitConditions;
    PersuitConditions.push_back(CONDITION_OBSTACLE);
    PersuitConditions.push_back(CONDITION_CAN_ATTACK);
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

    StartFrame = 0;
    EndFrame = 6;
    Frame = 0;

    Direction = 0;
    Action = eaStand;
}

void Enemy::Think()
{
    printf("Think!");
    GetConditions();
    if (FCurrentSchedule.IsCompleted(FConditions))
    {
        SelectNewSchedule();
    }
}

void Enemy::GetConditions()
{
    printf("GetConditions!\n");
    FConditions.Clear();

    Sense();

    FConditions.Add(CONDITION_CAN_STAND);
    FConditions.Add(CONDITION_CAN_WALK);
}

void Enemy::SelectNewSchedule()
{
    switch (FCurrentState) {
    case STATE_STAND:
        if (FConditions.Contains(CONDITION_CAN_ATTACK))
        {
            SetSchedule(SCHEDULE_ATTACK);
        }
        else if (FConditions.Contains(CONDITION_SEE_ENEMY))
        {
            SetSchedule(SCHEDULE_PURSUIT);
        }
        else if (!FConditions.Contains(CONDITION_OBSTACLE))
        {
            SetSchedule(SCHEDULE_WALK);
        }
        else
        {
            SetSchedule(SCHEDULE_STAND);
        }
        break;
    case STATE_WALK:
        if (FConditions.Contains(CONDITION_CAN_ATTACK))
        {
            SetSchedule(SCHEDULE_ATTACK);
        }
        else if (FConditions.Contains(CONDITION_SEE_ENEMY))
        {
            SetSchedule(SCHEDULE_PURSUIT);
        }
        else if (FConditions.Contains(CONDITION_OBSTACLE))
        {
            SetSchedule(SCHEDULE_STAND);
        }
        else
        {
            SetSchedule(SCHEDULE_WALK);
        }
        break;
    case STATE_PURSUIT:
        if (FConditions.Contains(CONDITION_CAN_ATTACK))
        {
            SetSchedule(SCHEDULE_ATTACK);
        }
        else if (!FConditions.Contains(CONDITION_SEE_ENEMY) || FConditions.Contains(CONDITION_OBSTACLE))
        {
            SetSchedule(SCHEDULE_STAND);
        }
        else
        {
            SetSchedule(SCHEDULE_PURSUIT);
        }
        break;
    case STATE_ATTACK:
        if (!FConditions.Contains(CONDITION_CAN_ATTACK) || (FConditions.Contains(CONDITION_OBSTACLE)))
        {
            SetSchedule(SCHEDULE_STAND);
        }
        else
        {
            SetSchedule(SCHEDULE_ATTACK);
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
            break;
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

void Enemy::Sense()
{
    for (int row = Dummy.x / TILE_SIZE; row <= (Dummy.x + Dummy.w) / TILE_SIZE; ++row) {
        for (int col = Dummy.y / TILE_SIZE; col <= (Dummy.y + Dummy.h) / TILE_SIZE; ++col) {
            char ch = Level->Map[col][row];
            switch (ch) {
            case '*':
                FConditions.Add(CONDITION_OBSTACLE);
                break;
            default:
                break;
            }
        }
    }

    int x1 = GetRect().x;
    int y1 = GetRect().y;
    int x2 = Level->Player.GetRect().x;
    int y2 = Level->Player.GetRect().y;

    int dist = hypot(x1 - x2, y1 - y2);
    if (dist < 40)
    {
        FConditions.Add(CONDITION_CAN_ATTACK);
    }
    else if (dist < 200)
    {
        FConditions.Add(CONDITION_SEE_ENEMY);
    }

}

bool Enemy::InitStand()
{
    printf("InitStand\n");

    Direction = rand() % 2;

    StartFrame = 0;
    EndFrame = 1;

    FActionDelay = rand() % 50 + 50;
    return true;
}

bool Enemy::Stand()
{
    printf("Stand\n");

    Action = eaStand;

    FActionDelay--;
    if (FActionDelay <= 0)
    {
        return true;
    }

    Animate();
    CheckCollision();

    return false;
}

bool Enemy::InitWalk()
{
    printf("InitWalk\n");

    StartFrame = 1;
    EndFrame = 10;

    SetSpeed(10.0f);

    FActionDelay = rand() % 50 + 50;
    return true;
}

bool Enemy::Walk()
{
    printf("Walk\n");

    FActionDelay--;
    if (FActionDelay <= 0)
    {
        return true;
    }

    switch (Direction) {
    case 0:
        Action = eaMoveLeft;
        MoveLeft();
        break;
    case 1:
        Action = eaMoveRight;
        MoveRight();
        break;
    default:
        break;
    }

    Animate();
    CheckCollision();

    return false;
}

bool Enemy::InitPursuit()
{
    printf("InitPursuit\n");

    StartFrame = 1;
    EndFrame = 10;

    SetSpeed(15.0f);

    FActionDelay = rand() % 50 + 50;
    return true;
}

bool Enemy::Pursuit()
{
    printf("Pursuit\n");

    FActionDelay--;
    if (FActionDelay <= 0)
    {
        return true;
    }

    SDL_Rect Rect = GetRect();
    if (Level->Player.GetRect().x < Rect.x)
    {
        Direction = 0;
    }
    else
    {
        Direction = 1;
    }

    switch (Direction) {
    case 0:
        Action = eaMoveLeft;
        MoveLeft();
        break;
    case 1:
        Action = eaMoveRight;
        MoveRight();
        break;
    default:
        break;
    }

    Animate();
    CheckCollision();

    return false;
}

bool Enemy::InitAttack()
{
    printf("InitAttack\n");

    StartFrame = 1;
    EndFrame = 3;

    SetSpeed(0.0f);

    return true;
}

bool Enemy::Attack()
{
    printf("Attack\n");

    SDL_Rect Rect = GetRect();
    if (Level->Player.GetRect().x < Rect.x)
    {
        Direction = 0;
    }
    else
    {
        Direction = 1;
    }

    switch (Direction) {
    case 0:
        Action = eaMoveLeft;
        break;
    case 1:
        Action = eaMoveRight;
        break;
    default:
        break;
    }

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

    Animate();
    CheckCollision();

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

    SDL_Rect Rect = GetRect();
    switch (Direction) {
    case 0:
        Dummy = Rect;
        Dummy.h = Rect.h - 2;
        Dummy.x -= 5;
        break;
    case 1:
        Dummy = Rect;
        Dummy.h = Rect.h - 2;
        Dummy.x += 5;
        break;
    default:
        break;
    }

    if (FAlert)
    {
        FAlertInterval--;
    }
}
