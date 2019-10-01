#include <cstdio>
long padoban[101];
int maxExpanded = 0;

int main(void)
{
    int T, N;
    scanf("%d", &T);

    padoban[1] = padoban[2] = padoban[3] = 1;
    padoban[4] = padoban[5] = 2;
    padoban[6] = 3;
    maxExpanded = 6;

    for (int tc = 1; tc <= T; tc++)
    {
        scanf("%d", &N);
        if (N <= maxExpanded)
        {
            printf("%ld \n", padoban[N]);
            continue;
        }
        for (int i = maxExpanded + 1; i <= N; i++)
            padoban[i] = padoban[i - 1] + padoban[i - 5];
        printf("%ld \n", padoban[N]);
    }
}