#include <iostream>
#include <cstdio>
#include <cmath>

int squareSumFinder_(int num, int squareSum, int maxBound, int depth)
{
    if (depth == 0 || maxBound == 0)
    {
        if (squareSum == num)
            return 1;
        else
            return 0;
    }

    if (squareSum > num)
        return 0;

    int matchCase = 0;
    for (int i = 0; i <= maxBound; i++)
        matchCase += squareSumFinder_(num, squareSum + i * i, i, depth - 1);
    return matchCase;
}

int squareSumFinder(int num)
{
    return squareSumFinder_(num, 0, int(sqrt(num)), 4);
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    int tcCnt, testNum;
    std::cin >> tcCnt;

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        std::cin >> testNum;
        std::cout << "#" << tc << " " << squareSumFinder(testNum) << std::endl;
    }
}