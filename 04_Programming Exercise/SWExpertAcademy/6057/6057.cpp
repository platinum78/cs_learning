#include <cstdio>
#include <memory.h>

bool connections[51][51];

void initConnections(void)
{
    for (int i = 0; i < 51; i++)
        for (int j = 0; j < 51; j++)
            connections[i][j] = false;
}

bool isConnected(int v1, int v2)
{
    return (connections[v1][v2] && connections[v2][v1]);
}

int main(void)
{
    freopen("input.txt", "r", stdin);

    int tcCnt;
    int vertexCnt, edgeCnt, trigCnt;
    int v1, v2, v3;
    scanf("%d", &tcCnt);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%d %d", &vertexCnt, &edgeCnt);
        for (int i = 0; i < edgeCnt; i++)
        {
            scanf("%d %d", &v1, &v2);
            connections[v1][v2] = connections[v2][v1] = true;
        }
        
        trigCnt = 0;
        for (v1 = 1; v1 <= vertexCnt - 2; v1++)
        {
            for (v2 = v1 + 1; v2 <= vertexCnt - 1; v2++)
            {
                if (!isConnected(v1, v2))
                    continue;
                for (v3 = v2 + 1; v3 <= vertexCnt; v3++)
                    if (isConnected(v2, v3) && isConnected(v1, v3))
                        ++trigCnt;
            }
        }

        printf("#%d %d \n", tc, trigCnt);
        initConnections();
    }
}