#ifndef CONDITIONLIST_H
#define CONDITIONLIST_H

#include <vector>
#include <algorithm>

class ConditionList
{
public:
    ConditionList();
    std::vector<int> Conditions;

    void Add(int ACondition);
    bool Contains(int ACondition);
    bool IsIntersects(ConditionList AConditionList);
    bool Empty();
    void Clear();
};

#endif // CONDITIONLIST_H
