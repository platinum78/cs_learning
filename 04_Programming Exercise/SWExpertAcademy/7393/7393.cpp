#include <cstdio>
#include <vector>

int main(void)
{
    freopen("input.txt", "r", stdin);
    std::vector< std::vector< std::vector<long> > > numbers(101);
    for (int i = 0; i < numbers.size(); i++)
    {
        numbers[i].resize(10);
        for (int j = 0; j < numbers[i].size(); j++)
        {
            numbers[i][j].resize(10);
            for (int k = 0; k < numbers[i][j].size(); k++)
                numbers[i][j][k] = 0;
        }
    }

    int tcCnt, tcNum, caseCnt;
    scanf("%d", &tcCnt);
    int len = 0, lenMaxExpanded = 9;

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%d", &tcNum);
        ++lenMaxExpanded;
        for (len = lenMaxExpanded; len <= tcNum; len++)
        {
            printf("%d \n", len);
            for (int firstDigit = 0; firstDigit <= 9; firstDigit++)
            {
                if (len == 10)
                {
                    if (firstDigit == 0)
                        numbers[len][firstDigit][9] = 1;
                    else if (firstDigit == 9)
                        numbers[len][firstDigit][0] = 1;
                }
                else
                {
                    if (firstDigit == 0)
                    {
                        for (int lastDigit = 0; lastDigit <= 9; lastDigit++)
                        {
                            if (lastDigit == 0)
                                numbers[len][1][lastDigit] = numbers[len][1][1];
                            else if (lastDigit == 9)
                                numbers[len][1][lastDigit] = numbers[len][1][8];
                            else
                                numbers[len][1][lastDigit] = (numbers[len][1][1] + numbers[len][1][8]) % 1000000000;
                        }
                    }
                    else if (firstDigit == 9)
                    {
                        for (int lastDigit = 0; lastDigit <= 9; lastDigit++)
                        {
                            if (lastDigit == 0)
                                numbers[len][8][lastDigit] = numbers[len][8][1];
                            else if (lastDigit == 9)
                                numbers[len][8][lastDigit] = numbers[len][8][8];
                            else
                                numbers[len][8][lastDigit] = (numbers[len][8][1] + numbers[len][8][8]) % 1000000000;
                        }
                    }
                    else
                    {
                        for (int lastDigit = 0; lastDigit <= 9; lastDigit++)
                        {
                            if (lastDigit == 0)
                                numbers[len][firstDigit][lastDigit] += numbers[len][firstDigit][1];
                            else if (lastDigit == 9)
                                numbers[len][firstDigit][lastDigit] += numbers[len][firstDigit][8];
                            else
                                numbers[len][firstDigit][lastDigit] += (numbers[len][firstDigit][1] + numbers[len][firstDigit][8]) % 1000000000;
                        }
                    }
                }
            }
        }
        --len;
        lenMaxExpanded = len;

        caseCnt = 0;
        for (int i = 1; i <= 9; i++)
            for (int j = 0; j <=9; j++)
            caseCnt += (numbers[tcNum][i][j] % 1000000000);
        
        printf("#%d %ld \n", tc, caseCnt % 1000000000);
    }
}