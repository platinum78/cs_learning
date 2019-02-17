// SWExpertAcademy Problem #1247
// Begin: 18 FEB 2019, 05:50

#include <iostream>
#include <vector>
#include <stdint.h>
#include <cmath>

typedef struct Point_
{
    int x;
    int y;
    bool visited;
} Point;

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int findMinDistance(std::vector<Point>& customerList, Point house, Point customerPrev,
                    int customersLeft, int totalDist)
{
    if (customersLeft == 0)
        return totalDist + abs(customerPrev.x - house.x) + abs(customerPrev.y - house.y);
    
    Point thisCustomer;
    int newDistance = totalDist;
    int minDistance = INT32_MAX;
    for (int i = 0; i < customerList.size(); i++)
    {
        if (customerList[i].visited)
            continue;
        
        thisCustomer = customerList[i];
        newDistance += abs(customerPrev.x - thisCustomer.x) + abs(customerPrev.y - thisCustomer.y);
        customerList[i].visited = true;
        minDistance = min(minDistance, findMinDistance(customerList, house, thisCustomer, customersLeft - 1, newDistance));
        customerList[i].visited = false;
        newDistance -= abs(customerPrev.x - thisCustomer.x) + abs(customerPrev.y - thisCustomer.y);
    }

    return minDistance;
}

int main(void)
{
    int tcCnt, customerCnt, minDist;
    Point house, company;
    std::vector<Point> customerList;
    std::cin >> tcCnt;
    
    for (int tc = 1; tc <= tcCnt; tc++)
    {
        std::cin >> customerCnt;
        customerList.resize(customerCnt);
        std::cin >> company.x >> company.y;
        std::cin >> house.x >> house.y;
        for (int i = 0; i < customerCnt; i++)
            std::cin >> customerList[i].x >> customerList[i].y;
        
        minDist = findMinDistance(customerList, house, company, customerCnt, 0);
        std::cout << "#" << tc << " " << minDist << std::endl;
    }
}