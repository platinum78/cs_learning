#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

struct GridPoint
{
    int cost;
    int total_cost;
    bool visited;
    int from;
};

GridPoint *makeNewGridPoint(int cost)
{
    GridPoint *pNewGP = new GridPoint;
    pNewGP->cost = cost;
    pNewGP->total_cost = 0;
    pNewGP->visited = false;
    pNewGP->from = 0;
    return pNewGP;
}

bool GridPointCostComp(GridPoint *p1, GridPoint *p2)
{
    return (p1->total_cost < p2->total_cost);
}

int findMinCost(std::vector<GridPoint*> &gridMap, int srcIdx, int destIdx)
{
    std::list<GridPoint*> active;
    GridPoint *pGridPoint = gridMap[srcIdx];

    active.push_back(pGridPoint);
    std::push_heap(active.begin(), active.end(), GridPointCostComp);

    while (true)
    {
        if (active.empty())
            return -1;
    }
}