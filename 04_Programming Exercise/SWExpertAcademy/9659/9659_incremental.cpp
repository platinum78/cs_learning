#include <cstdio>

int poly[51][3];
long val[51] = {1, };

int main(void)
{
    freopen("./input.txt", "r", stdin);
    int t, a, b, x;
    int tcCnt, polyCnt, numCnt;
    scanf("%d", &tcCnt);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%d", &polyCnt);
        for (int i = 2; i <= polyCnt; i++)
            scanf("%d %d %d", &poly[i][0], &poly[i][1], &poly[i][2]);

        printf("#%d ", tc);
        
        scanf("%d", &numCnt);
        for (int i = 0; i < numCnt; i++)
        {
            scanf("%d", &x);
            val[1] = x;
            for (int j = 2; j <= polyCnt; j++)
            {
                if (poly[j][0] == 1)
                    val[j] = (val[poly[j][1]] + val[poly[j][2]]) % 998244353;
                else if (poly[j][0] == 2)
                    val[j] = (poly[j][1] * val[poly[j][2]]) % 998244353;
                else
                    val[j] = (val[poly[j][1]] * val[poly[j][2]]) % 998244353;
            }
            printf("%ld ", val[polyCnt]);
        }

        printf("\n");
    }
}