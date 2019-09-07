#include <cstdio>

int s, t, a, b;

int dfs()
{
    int days = 0;
    if (t < s) return -1;
    if (b == 1)
    {
        if ((t - s) % b)
            return -1;
        else
            return (t - s) / b;
    }
    while (1)
    {
        if (t < s)
            return -1;
        if (t == s)
            return days;
        if (t % b == 0)
        {
            t /= b;
            if (t < s)
            {
                t *= b;
                t -= a;
            }
        }
        else
            t -= a;
        days++;
    }
}

int main(void)
{
    freopen("input.txt", "r", stdin);

    
    int T, days;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
    {
        scanf("%d %d %d %d", &s, &t, &a, &b);
        printf("#%d %d \n", tc, dfs());
    }
}