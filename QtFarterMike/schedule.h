#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "conditionlist.h"
#include <vector>

class Enemy;

typedef bool (Enemy::*func)();

class Schedule
{
private:
    std::vector<func> FTasks;
    unsigned FTaskIndex;
    ConditionList FInterrupts;
    bool FCompleted;

public:
    Schedule();
    int Type;
    void AddTask(func ATask);
    void AddTasks(std::vector<func> ATasks);
    void AddInterrupt(int AInterrupt);
    void AddInterrupts(std::vector<int> AInterrupts);
    void Update(Enemy* enemy);
    void Complete();
    bool IsCompleted(ConditionList AConditionList);
    void Reset();
};

#endif // SCHEDULE_H
