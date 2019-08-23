#include <cstdio>

int main(void)
{
    freopen("input.txt", "r", stdin);
    int tcCnt, tcNumCnt, acc = 0;
    int numbers[9];
    scanf("%d", &tcCnt);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        acc = 0;
        scanf("%d", &tcNumCnt);
        for (int i = 0; i < tcNumCnt; i++)
            scanf("%d", numbers + i);
        
        acc += numbers[0];
        for (int i = 1; i < tcNumCnt; i++)
        {
            if (acc <= 1 || numbers[i] <= 1)
                acc += numbers[i];
            else
                acc *= numbers[i];
        }

        printf("#%d %d \n", tc, acc);
    }

    return 0;
}