#include <cstdio>

int order[1001];
bool visited[1001];
int nodeCnt;
int loopPos, loopLen;
bool **cxnMat;

bool dfs(int node, int prev, int depth)
{
    order[node] = depth;
    bool found = false;

    for (int i = 1; i <= nodeCnt; i++)
    {
        if (cxnMat[node][i])
        {
            if (!visited[i])
            {
                visited[i] = true;
                found = dfs(i, node, depth + 1);
                visited[i] = false;
                if (found)
                    return true;
            }
            else if (i != prev)
            {
                loopPos = i;
                loopLen = depth - order[i] + 1;
                return true;
            }
        }
    }
    return false;
}

int main(void)
{
    freopen("input.txt", "r", stdin);

    cxnMat = new bool*[1001];
    for (int i = 0; i < 1001; i++)
        cxnMat[i] = new bool[1001];

    int tcCnt, edgeCnt, x, y;
    scanf("%d", &tcCnt);
    
    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%d", &edgeCnt);
        nodeCnt = edgeCnt;
        for (int i = 0; i <= edgeCnt; i++)
        {
            visited[i] = false;
            for (int j = 0; j <= edgeCnt; j++)
                cxnMat[i][j] = false;
        }

        for (int i = 0; i < edgeCnt; i++)
        {
            scanf("%d %d", &x, &y);
            cxnMat[x][y] = cxnMat[y][x] = true;
        }
        
        dfs(1, 0, 0);
        printf("#%d %d \n", tc, loopLen);
    }
}