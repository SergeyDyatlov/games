#include "schedule.h"
#include "enemy.h"

Schedule::Schedule()
{
    FTaskIndex = 0;
    FCompleted = false;
}

void Schedule::AddTask(func ATask)
{
    FTasks.push_back(ATask);
}

void Schedule::AddTasks(std::vector<func> ATasks)
{
    FTasks.insert(FTasks.end(), ATasks.begin(), ATasks.end());
}

void Schedule::AddInterrupt(int AInterrupt)
{
    FInterrupts.Add(AInterrupt);
}

void Schedule::AddInterrupts(std::vector<int> AInterrupts)
{
    for (std::vector<int>::iterator item = AInterrupts.begin(); item != AInterrupts.end(); item++)
    {
        FInterrupts.Add(*item);
    }
}

void Schedule::Update(Enemy* enemy)
{
    if (FCompleted)
    {
        return;
    }

    func Task = FTasks.at(FTaskIndex);
    if (Task != NULL)
    {
        if ((enemy->*(Task))())
        {
            FTaskIndex++;
            if (FTaskIndex >= FTasks.size())
            {
                Complete();
            }
        }
    }
    else
    {
        Complete();
    }
}

void Schedule::Complete()
{
    FTaskIndex = 0;
    FCompleted = true;
}

bool Schedule::IsCompleted(ConditionList AConditionList)
{
    if (FInterrupts.IsIntersects(AConditionList))
    {
        return true;
    }

    return FCompleted;
}
