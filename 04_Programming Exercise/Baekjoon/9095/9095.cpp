#include <cstdio>

int dp[11] = { 0, };
int maxExpanded;

int findCase(int num)
{
    if (num == 0)
        return 1;
    if (num < 0)
        return 0;
    
    int localCase = 0;
    int globalCase = 0;
    for (int i = 1; i <= 3 && i <= num; i++)
    {
        if (dp[num - i] > 0)
            globalCase += dp[num - i];
        else
        {
            localCase = findCase(num - i);
            dp[num - i] = localCase;
            globalCase += localCase;
        }
    }

    return globalCase;
}

int main(void)
{
    dp[0] = 0;
    dp[1] = 1;
    maxExpanded = 1;

    int tcCnt, tNum;
    scanf("%d", &tcCnt);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%d", &tNum);
        printf("%d \n", findCase(tNum));
    }
}