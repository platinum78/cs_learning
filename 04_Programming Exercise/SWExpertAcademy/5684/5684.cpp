#include <cstdio>

int **cxnMat = NULL;
bool *visited = NULL;
int N, M;
int s, e, c;
int maxLen = 0x7FFFFFFF;

int min(int a, int b)
{
    return (a < b ? a : b);
}

int dfs(int src, int loc, int len)
{
    if (len >= maxLen)
        return 0x7FFFFFFF;
    
    if (len > 0 && src == loc)
    {
        maxLen = len;
        return len;
    }

    int path_len = 0x7FFFFFFF;

    for (int i = 1; i <= N; i++)
    {
        printf("%d %d \n", loc, i);
        if (cxnMat[loc][i] && !visited[i])
        {
            visited[i] = true;
            path_len = min(path_len, dfs(src, i, len + cxnMat[loc][i]));
            visited[i] = false;
        }
    }

    return path_len;
}

int main(void)
{
    freopen("input.txt", "r", stdin);

    cxnMat = new int*[401];
    for (int i = 0; i < 401; i++) cxnMat[i] = new int[401];
    visited = new bool[401];

    int tcCnt;
    scanf("%d", &tcCnt);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%d %d", &N, &M);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cxnMat[i][j] = 0;

        for (int n = 1; n <= M; n++)
        {
            scanf("%d %d %d", &s, &e, &c);
            cxnMat[s][e] = c;
        }

        maxLen = 0x7FFFFFFF;
        for (int i = 1; i <= N; i++)
            dfs(i, i, 0);
        
        printf("#%d %d \n", tc, maxLen);
    }
}