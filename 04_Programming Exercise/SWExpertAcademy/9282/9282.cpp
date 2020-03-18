#include <cstdio>
#include <memory.h>

long chocoMap[51][51] = { {0, } };
long chocoSumH[51][51] = { {0, } };
long chocoSumV[51][51] = { {0, } };
long dp[51][51][51][51];    // tlRow, tlCol. height, width 순서로 저장

long minChoco(int tlRow, int tlCol, int height, int width)
{
    if (height == 1 && width == 1)
        return 0;
    
    if (dp[tlRow][tlCol][height][width] > 0)
        return dp[tlRow][tlCol][height][width];
    
    long choco, choco1, choco2;
    long minimum = __LONG_MAX__;

    choco = 0;
    if (width > height)
        for (int i = tlRow; i < tlRow + height; i++)
            choco += chocoSumH[i][tlCol + width - 1] - chocoSumH[i][tlCol - 1];
    else
        for (int i = tlCol; i < tlCol + width; i++)
            choco += chocoSumV[tlRow + height - 1][i] - chocoSumV[tlRow - 1][i];

    // 가로 자르기 검증
    for (int i = 1; i < height; i++)
    {
        if (dp[tlRow][tlCol][i][width] > 0)
            choco1 = dp[tlRow][tlCol][i][width];
        else
        {
            choco1 = minChoco(tlRow, tlCol, i, width);
            dp[tlRow][tlCol][i][width] = choco1;
        }
        if (dp[tlRow + i][tlCol][height - i][width] > 0)
            choco2 = dp[tlRow + i][tlCol][height - i][width];
        else
        {
            choco2 = minChoco(tlRow + i, tlCol, height - i, width);
            dp[tlRow + i][tlCol][height - i][width] = choco2;
        }
        
        minimum = (choco1 + choco2 < minimum ? choco1 + choco2 : minimum);
    }

    for (int i = 1; i < width; i++)
    {
        if (dp[tlRow][tlCol][height][i] > 0)
            choco1 = dp[tlRow][tlCol][height][i];
        else
        {
            choco1 = minChoco(tlRow, tlCol, height, i);
            dp[tlRow][tlCol][height][i] = choco1;
        }
        
        if (dp[tlRow][tlCol + i][height][width - i] > 0)
            choco2 = dp[tlRow][tlCol + i][height][width - i];
        else
        {
            choco2 = minChoco(tlRow, tlCol + i, height, width - i);
            dp[tlRow][tlCol + i][height][width - i] = choco2;
        }

        minimum = (choco1 + choco2 < minimum ? choco1 + choco2 : minimum);
    }

    return choco + minimum;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    int tcCnt, n, m;
    
    scanf("%d", &tcCnt);
    for (int tc = 1; tc <= tcCnt; tc++)
    {
        memset(dp, '\0', 51 * 51 * 51 * 51 * sizeof(long));
        memset(chocoSumH, '\0', 51 * 51 * sizeof(int));
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                scanf("%ld", &chocoMap[i][j]);
                chocoSumH[i][j] = chocoSumH[i][j-1] + chocoMap[i][j];
                chocoSumV[i][j] = chocoSumV[i-1][j] + chocoMap[i][j];
            }
        printf("#%d %ld \n", tc, minChoco(1, 1, n, m));
    }
}