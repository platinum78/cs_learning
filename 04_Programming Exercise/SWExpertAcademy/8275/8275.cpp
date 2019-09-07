#include <cstdio>

int population[7];
int answer[7];
int max = 0;
int records[10][3];
int N, X, M;
bool found;

void dfs(int N, int n, int x, int m)
{
    if (n == 0)
    {
        int sum = 0;
        for (int i = 0; i < m; i++)
        {
            sum = 0;
            for (int j = records[i][0]; j <= records[i][1]; j++)
                sum += population[j];
            if (sum != records[i][2])
                return;
            
        }

        sum = 0;
        for (int j = 1; j <= N; j++)
            sum += population[j];
        if (sum > max)
        {
            for (int j = 1; j <= N; j++)
                answer[j] = population[j];
            max = sum;
        }
        found = true;
        return;
    }

    for (int i = 0; i <= x; i++)
    {
        population[N - n + 1] = i;
        dfs(N, n - 1, x, m);
            // return true;
    }

    // return false;
}

int main(void)
{
    freopen("input.txt", "r", stdin);

    int tcCnt;
    scanf("%d", &tcCnt);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%d %d %d", &N, &X, &M);
        for (int m = 0; m < M; m++)
            scanf("%d %d %d", &records[m][0], &records[m][1], &records[m][2]);

        max = 0;
        found = false;
        dfs(N, N, X, M);
        if (found)
        {
            printf("#%d ", tc);
            for (int i = 1; i <= N; i++)
                printf("%d ", answer[i]);
            printf("\n");
        }
        else
            printf("#%d -1 \n", tc);
    }
}
