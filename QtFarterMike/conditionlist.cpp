#include "conditionlist.h"

ConditionList::ConditionList()
{
}

void ConditionList::Add(int ACondition)
{
    Conditions.push_back(ACondition);
}

bool ConditionList::Contains(int ACondition)
{
    return std::find(Conditions.begin(), Conditions.end(), ACondition) != Conditions.end();
}

bool ConditionList::IsIntersects(ConditionList AConditionList)
{
    if (Conditions.empty() || AConditionList.Empty())
    {
        return false;
    }

    for (std::vector<int>::iterator item = AConditionList.Conditions.begin(); item != AConditionList.Conditions.end(); item++)
    {
        return Contains(*item);
    }

    return false;
}

bool ConditionList::Empty()
{
    return Conditions.empty();
}

void ConditionList::Clear()
{
    Conditions.clear();
}
