#include <cstdio>
#include <vector>

int main(void)
{
    freopen("input.txt", "r", stdin);

    std::vector< std::vector<int> > connections(51);
    for (int i = 0; i < connections.size(); i++)
    {
        connections[i].resize(51);
        for (int j = 0; j < connections[i].size(); j++)
            connections[i][j] = 0;
    }

    int tcCnt, N, M;
    int n1, n2, n3;
    int trigCnt;
    scanf("%d", &tcCnt);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%d %d", &N, &M);
        if (N >= 3 && M >= 3)
        {
            for (int m = 0; m < M; m++)
            {
                scanf("%d %d", &n1, &n2);
                connections[n1][n2] = 1;
                connections[n2][n1] = 1;
            }

            trigCnt = 0;
            for (int n1 = 1; n1 <= N - 2; n1++)
            {
                for (int n2 = n1 + 1; n2 <= N - 1; n2++)
                {
                    if (!connections[n1][n2])
                        continue;
                    for (int n3 = n2 + 1; n3 <= N; n3++)
                        if (connections[n2][n3] && connections[n1][n3])
                            ++trigCnt;
                }
            }
            printf("#%d %d \n", tc, trigCnt);

            for (int m = 0; m < M; m++)
                connections[n1][n2] = false;
        }
        else
        {
            printf("#%d 0 \n", tc);
        }

    }

    return 0;
}
