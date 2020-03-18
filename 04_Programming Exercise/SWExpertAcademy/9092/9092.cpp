#include <cstdio>
#include <memory.h>

int dp[501][501] = { {0, } };
int points[501][2];
int n, k;

int min(int a, int b)
{
    return (a < b ? a : b);
}

int manhattanDist(int p1, int p2)
{
    return (points[p1][0] > points[p2][0] ? points[p1][0] - points[p2][0] : points[p2][0] - points[p1][0]) +
           (points[p1][1] > points[p2][1] ? points[p1][1] - points[p2][1] : points[p2][1] - points[p1][1]);
}

int findMinDist(int ckpt, int remaining)
{
    if (remaining == 0)
        return manhattanDist(ckpt, n);
    
    if (dp[ckpt][remaining] > 0)
        return dp[ckpt][remaining];

    int minDist = __INT_MAX__;
    
    for (int p = ckpt + 1; p <= n - remaining; p++)
    {
        if (dp[p][remaining - 1] == 0)
            dp[p][remaining - 1] = findMinDist(p, remaining - 1);
        minDist = min(minDist, manhattanDist(ckpt, p) + dp[p][remaining - 1]);
    }
    
    return minDist;
}

int main(void)
{
    freopen("input.txt", "r", stdin);

    int tcCnt;
    scanf("%d", &tcCnt);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        memset(dp, '\0', 501 * 501 * sizeof(int));
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++)
            scanf("%d %d", &points[i][0], &points[i][1]);
        printf("#%d %d \n", tc, findMinDist(1, n - k - 2));
    }
}