#include <cstdio>

int main(void)
{
    int tcCnt;
    int n1, n2;
    scanf("%d", &tcCnt);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%d %d", &n1, &n2);
        if (n2 < n1)
        {
            int buf = n2;
            n2 = n1;
            n1 = buf;
        }
        for (int i = n1 + 1; i <= n2 + 1; i++)
            printf("%d ", i);
        printf("\n");
    }
}