#include <cstdio>

int coordinates[10][2];
int N;
int visited = 0;
int dpTable[1024][10];
int minDist;
int hx, hy, cx, cy;

int min(int a, int b)
{
    return (a < b ? a : b);
}

int abs(int a)
{
    return (a > 0 ? a : -a);
}

int mDist(int i, int j)
{
    return abs(coordinates[i][0] - coordinates[j][0]) +
            abs(coordinates[i][1] - coordinates[j][1]);
}

int dp(int visited, int loc)
{
    if (visited == (1 << N) - 1)
    {
        int dist_ = abs(coordinates[loc][0] - hx) + abs(coordinates[loc][1] - hy);
        return dist_;
    }
    
    int dist_, dist__ = 0x1FFFFFFF;
    int visited_;
    for (int i = 0; i < N; i++)
    {
        if (!(visited & (1 << i)))
        {
            visited_ = visited | (1 << i);
            if (dpTable[visited_][i])
                dist_ = dpTable[visited_][i];
            else
            {
                dist_ = dp(visited_, i);
                dpTable[visited_][i] = dist_;
            }
            visited_ = visited;
            dist__ = min(dist__, dist_ + mDist(loc, i));
        }
    }
    dpTable[visited][loc] = dist__;
    return dist__;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    int x, y;
    int tcCnt;
    scanf("%d", &tcCnt);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%d", &N);
        scanf("%d %d %d %d", &cx, &cy, &hx, &hy);
        for (int i = 0; i < N; i++)
        {
            scanf("%d %d", &x, &y);
            coordinates[i][0] = x;
            coordinates[i][1] = y;
            for (int j = 0; j < 1024; j++)
                dpTable[j][i] = 0;
        }
        
        int dist_ = __INT_MAX__;
        for (int i = 0; i < N; i++)
            dist_ = min(dist_, dp(1 << i, i) + abs(coordinates[i][0] - cx) + abs(coordinates[i][1] - cy));
        printf("#%d %d \n", tc, dist_);
    }
}