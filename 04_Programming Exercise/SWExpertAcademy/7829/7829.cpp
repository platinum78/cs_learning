#include <cstdio>

int main(void)
{
    int tcCnt, numCnt;
    int div, minDiv, maxDiv;
    scanf("%d", &tcCnt);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        minDiv = __INT_MAX__;
        maxDiv = __INT_MAX__ + 1;

        scanf("%d", &numCnt);
        for (int i = 0; i < numCnt; i++)
        {
            scanf("%d", &div);
            minDiv = (div < minDiv ? div : minDiv);
            maxDiv = (div > maxDiv ? div : maxDiv);
        }

        printf("#%d %d \n", tc, minDiv * maxDiv);
    }
}