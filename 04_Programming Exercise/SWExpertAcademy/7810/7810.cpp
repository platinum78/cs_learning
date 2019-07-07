#include <cstdio>
#include <memory.h>

int main(void)
{
    freopen("input.txt", "r", stdin);

    int *series = new int[1000001];
    int tcCnt, numCnt, num, accGeq;
    scanf("%d", &tcCnt);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%d", &numCnt);
        memset(series, '\0', 1000001 * sizeof(int));

        for (int i = 0; i < numCnt; i++)
        {
            scanf("%d", &num);
            series[num]++;
        }

        accGeq = 0;

        for (int i = 1000000; i >= 0; i--)
        {
            accGeq += series[i];
            if (i <= accGeq)
            {
                printf("#%d %d \n", tc, i);
                break;
            }
        }
    }

    delete[] series;
}