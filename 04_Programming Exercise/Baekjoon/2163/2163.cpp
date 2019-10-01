#include <cstdio>
#include <memory.h>

int minSplit[301][301];

int findMinSplit(int row, int col)
{
    if (row == 1 && col == 1)
        return 0;
    
    int r1, r2, c1, c2;
    if (row >= col)
    {
        if (row % 2 == 0)
            r1 = row / 2;
        else
            r1 = (row + 1) / 2;
        r2 = row - r1;
        c1 = c2 = col;
    }
    else
    {
        if (col % 2 == 0)
            c1 = col / 2;
        else
            c1 = (col + 1) / 2;
        c2 = col - c1;
        r1 = r2 = row;
    }

    int splitCnt = 1;
    if (minSplit[r1][c1] > 0)
        splitCnt += minSplit[r1][c1];
    else
    {
        minSplit[r1][c1] = findMinSplit(r1, c1);
        splitCnt += minSplit[r1][c1];
    }
    
    if (minSplit[r2][c2] > 0)
        splitCnt += minSplit[r2][c2];
    else
    {
        minSplit[r2][c2] = findMinSplit(r2, c2);
        splitCnt += minSplit[r2][c2];
    }

    return splitCnt;
}

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= M; j++)
            minSplit[i][j] = 0;

    printf("%d \n", findMinSplit(N, M));
}