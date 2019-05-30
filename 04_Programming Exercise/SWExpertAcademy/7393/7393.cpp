#include <iostream>
#include <vector>

int main(void)
{
    // Replace stdin with file.
    freopen("input.txt", "r", stdin);

    // Define parameters.
    int tcCnt;
    std::cin >> tcCnt;
    int maxLen = 10, tcLen;
    int tcMatchCnt;

    // Create and initialize table for DP.
    std::vector< std::vector<long> > numbers(101);
    for (int i = 0; i < numbers.size(); i++)
    {
        numbers[i].resize(10);
        for (int j = 0; j < numbers[i].size(); j++)
            numbers[i][j] = 0;
    }
    numbers[10][0] = numbers[10][9] = 1;

    // Evaluate test cases.
    for (int tc = 1; tc <= tcCnt; tc++)
    {
        std::cin >> tcLen;
        for (int len = ++maxLen; len <= tcLen; len++)
        {
            printf("len = %d \n", len);
            for (int firstDigit = 0; firstDigit <= 9; firstDigit++)
            {
                if (firstDigit == 0)
                    numbers[len][0] = numbers[len - 1][1];
                else if (firstDigit == 9)
                    numbers[len][9] = numbers[len - 1][8];
                else
                    numbers[len][firstDigit] = numbers[len - 1][firstDigit + 1] +
                                               numbers[len - 1][firstDigit - 1];
            }
        }
        maxLen = tcLen;

        tcMatchCnt = 0;
        for (int i = 1; i <= 9; i++)
            tcMatchCnt += numbers[tcLen][i];
        
        printf("#%d %d \n", tc, tcMatchCnt);
    }
}