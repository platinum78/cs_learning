#include <iostream>
#include <cmath>
#include <cstdio>

int squareSumFinder(int num)
{
    int n1, n2, n3, n4;
    int squareSum1, squareSum2, squareSum3, squareSum4;
    int matchCase = 0;

    squareSum1 = 0;
    for (n1 = 0; n1 <= num && n1 * n1 <= num; n1++)
    {
        squareSum1 = n1 * n1;
        for (n2 = 0; n2 <= n1 && squareSum1 + n2 * n2 <= num; n2++)
        {
            squareSum2 = squareSum1 + n2 * n2;
            for (n3 = 0; n3 <= n2 && squareSum2 + n3 * n3 <= num; n3++)
            {
                squareSum3 = squareSum2 + n3 * n3;
                for (n4 = 0; n4 <= n3 && squareSum3 + n4 * n4 <= num; n4++)
                {
                    squareSum4 = squareSum3 + n4 * n4;
                    if (squareSum4 == num)
                    {
                        ++matchCase;
                        break;
                    }
                }
            }
        }
    }

    return matchCase;
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