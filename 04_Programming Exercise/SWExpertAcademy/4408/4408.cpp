// SWExpertAcademy Problem #4408
// Begin: 18 FEB 2019, 04:39

#include <iostream>
#include <vector>
#include <cstdio>

typedef struct Interval_
{
    int start;
    int finish;
    bool traversed;
} Interval;

bool isOverlapped(std::vector<bool>& travelMap, Interval int1)
{
    int start1 = (int1.start + 1) / 2;
    int finish1 = (int1.finish + 1) / 2;

    for (int i = start1; i <= finish1; i++)
        if (travelMap[i])
            return true;
    return false;
}

void markTraversed(std::vector<bool>& travelMap, Interval int1)
{
    int start1 = (int1.start + 1) / 2;
    int finish1 = (int1.finish + 1) / 2;

    for (int i = start1; i <= finish1; i++)
        travelMap[i] = true;
}

int findMinTime(std::vector<Interval>& intervals)
{
    std::vector<bool> travelMap(200, false);
    int moreToGo = intervals.size();
    int intervalOnMap;
    int timeSteps = 0;
    while (moreToGo > 0)
    {
        std::cout << timeSteps << std::endl;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i].traversed)
                continue;
            if (!isOverlapped(travelMap, intervals[i]))
            {
                intervals[i].traversed = true;
                markTraversed(travelMap, intervals[i]);
                --moreToGo;
            }
        }
        ++timeSteps;
        for (int i = 0; i < travelMap.size(); i++)
            travelMap[i] = false;
    }

    return timeSteps;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    int tcCnt;
    int studentCnt, minTimeStep;
    std::cin >> tcCnt;
    std::vector<Interval> intervals;

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        std::cin >> studentCnt;
        intervals.resize(studentCnt);

        for (int s = 0; s < studentCnt; s++)
        {
            std::cin >> intervals[s].start >> intervals[s].finish;
            intervals[s].traversed = false;
        }
        
        minTimeStep = findMinTime(intervals);
        std::cout << "#" << tc << " " << minTimeStep << std::endl;
    }

    return 0;
}

