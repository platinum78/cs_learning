#include <cstdio>
#include <cstdlib>
#include <memory.h>

long poly[51][3];   // t, a, b 순서대로 저장
long val[51];

long computePoly(int i, long x)
{
    if (i == 0)
        return 1;
    else if (i == 1)
        return x;
    
    if (val[i] > 0)
        return val[i];
    
    if (poly[i][0] == 1)
        return computePoly(poly[i][1], x) + computePoly(poly[i][2], x);
    else if (poly[i][0] == 2)
        return poly[i][1] * computePoly(poly[i][2], x);
    else
        return computePoly(poly[i][1], x) * computePoly(poly[i][2], x);
}

int main(void)
{
    freopen("./input.txt", "r", stdin);
    int num;
    int tcCnt, polyCnt, numCnt;
    scanf("%d", &tcCnt);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%d", &polyCnt);
        for (int i = 2; i <= polyCnt; i++)
            scanf("%ld %ld %ld", &poly[i][0], &poly[i][1], &poly[i][2]);
        
        printf("#%d ", tc);
        
        scanf("%d", &numCnt);
        for (int i = 0; i < numCnt; i++)
        {
            memset(val, '\0', 51 * sizeof(int));
            scanf("%d", &num);
            printf("%ld ", computePoly(polyCnt, num));
        }
        printf("\n");
    }
}