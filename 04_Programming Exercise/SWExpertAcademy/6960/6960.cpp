// SWExpertAcademy Problem #6960
// Begin: 18 FEB 2018, 03:00
// Quit: 18 FEB 2018, 03:57

#include <iostream>
#include <vector>
#include <cstdio>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int findMaxFirstSolve(std::vector<int>& jyTime, std::vector<int>& competitorTime, 
                      int iteration, int totalTime, int firstSolve, int maxTime)
{
    if (iteration == 0 || totalTime > maxTime)
        return firstSolve;
    
    int maxFirstSolve = 0, newTotalTime = totalTime, newFirstSolve = firstSolve;
    for (int i = 0; i < jyTime.size(); i++)
    {
        if (jyTime[i] < 0)
            continue;
        newTotalTime += jyTime[i];
        if (newTotalTime <= competitorTime[i])
            ++newFirstSolve;
        jyTime[i] *= -1;
        maxFirstSolve = max(maxFirstSolve, findMaxFirstSolve(jyTime, competitorTime, iteration - 1, newTotalTime, newFirstSolve, maxTime));
        jyTime[i] *= -1;
        if (newTotalTime <= competitorTime[i])
            --newFirstSolve;
        newTotalTime -= jyTime[i];
    }

    return maxFirstSolve;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    int tcCnt, questionCnt, maxFirstSolve, maxTime = 0;
    std::cin >> tcCnt;
    std::vector<int> jyTime;
    std::vector<int> competitorTime;

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        std::cin >> questionCnt;
        maxTime = 0;
        jyTime.resize(questionCnt);
        competitorTime.resize(questionCnt);

        for (int q = 0; q < questionCnt; q++)
        {
            std::cin >> jyTime[q] >> competitorTime[q];
            maxTime = max(maxTime, competitorTime[q]);
        }
        std::cout << maxTime << std::endl;
        maxFirstSolve = findMaxFirstSolve(jyTime, competitorTime, questionCnt, 0, 0, maxTime);

        std::cout << "#" << tc << " " << maxFirstSolve << std::endl;
    }

    return 0;
}