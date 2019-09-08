#include <cstdio>

int maxOdd(int x)
{
    if (x % 2)
        return x;
    else
        return x - 1;
}

int maxEven(int x)
{
    if (!(x % 2))
        return x;
    else
        return x - 1;
}

int abs(int x)
{
    return (x > 0 ? x : -x);
}

int main(void)
{
    freopen("input.txt", "r", stdin);

    int tcCnt;
    int row, col, iter;
    int oddCnt, evenCnt, dist, maxDist;
    int pointCnt;

    scanf("%d", &tcCnt);
    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%d", &pointCnt);
        maxDist = -1;
        oddCnt = evenCnt = 0;
        for (int i = 0; i < pointCnt; i++)
        {
            scanf("%d %d", &row, &col);
            dist = abs(row) + abs(col);
            if (dist % 2)
                evenCnt++;
            else
                oddCnt++;
            maxDist = (dist > maxDist ? dist : maxDist);
        }

        if (evenCnt && oddCnt)
        {
            printf("#%d -1 \n", tc);
            continue;
        }

        iter = 0;
        while (maxDist != 0)
        {
            iter++;
            if (iter % 2)
                maxDist -= maxOdd((maxDist < iter ? maxDist : iter));
            else
                maxDist -= maxEven((maxDist < iter ? maxDist : iter));
        }

        printf("#%d %d \n", tc, iter);
    }

    return 0;
}