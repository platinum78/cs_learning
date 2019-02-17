#include <iostream>
#include <vector>
#include <cstdio>

#define NO_PATH -1000
#define VISITED -2000

bool isReachable(std::vector<int> &leftReach, std::vector<int> &rightReach, int startPoint)
{
    // If reached destination
    if (startPoint == 99)
        return true;
    // If formed cycle
    if (leftReach[startPoint] < 0 && rightReach[startPoint] < 0)
        return false;
    
    int nextPoint;
    bool reachable = false;

    if (leftReach[startPoint] >= 0)
    {
        nextPoint = leftReach[startPoint];
        leftReach[startPoint] *= -1;
        reachable += isReachable(leftReach, rightReach, nextPoint);
        leftReach[startPoint] *= -1;
    }
    if (rightReach[startPoint] >= 0)
    {
        nextPoint = rightReach[startPoint];
        rightReach[startPoint] *= -1;
        reachable += isReachable(leftReach, rightReach, nextPoint);
        rightReach[startPoint] *= -1;
    }

    return reachable;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    std::vector<int> leftReach(100, NO_PATH);
    std::vector<int> rightReach(100, NO_PATH);

    int tcCnt, tcNum, roadCnt;
    int startNum, destNum;
    bool reachable;

    for (int tc = 1; tc <= 10; tc++)
    {
        std::cin >> tcNum >> roadCnt;
        for (int i = 0; i < 100; i++)
        {
            leftReach[i] = NO_PATH;
            rightReach[i] = NO_PATH;
        }
        for (int i = 0; i < roadCnt; i++)
        {
            std::cin >> startNum;
            std::cin >> destNum;

            if (leftReach[startNum] == NO_PATH)
                leftReach[startNum] = destNum;
            else
                rightReach[startNum] = destNum;
        }
        
        reachable = isReachable(leftReach, rightReach, 0);

        if (reachable)
            std::cout << "#" << tc << " 1" << std::endl;
        else
            std::cout << "#" << tc << " 0" << std::endl;
    }

    return 0;
}