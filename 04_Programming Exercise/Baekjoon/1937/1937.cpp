#include <cstdio>

#define MAX(X, Y)   (X > Y ? X : Y)

int forest[500][500];
int maxDays[500][500];
bool visited[500][500];
int offsetDir[500][500];
int offset[4][2] = { { 0, 1 }, { -1, 0 }, { 0, -1 }, { 1, 0 } };
int mapSize, maxDay;

bool isIdxInRange(int row, int col)
{
    if (row < 0 || row >= mapSize)
        return false;
    if (col < 0 || col >= mapSize)
        return false;
    return true;
}

bool checkPathOverlap(int row, int col)
{
    int dx, dy, dir;
    while (offsetDir[row][col] != -1)
    {
        if (visited[row][col])
            return true;
        dir = offsetDir[row][col];
        row += offset[dir][0];
        col += offset[dir][1];
    }
    return false;
}

int maxSurvival(int row, int col)
{
    static int callCnt = 0;
    // printf("Call cnt: %d \n", ++callCnt);
    int maxFromHere = 0;
    for (int i = 0; i < 4; i++)
    {
        int &dr = offset[i][0];
        int &dc = offset[i][1];
        
        if (isIdxInRange(row + dr, col + dc) && forest[row + dr][col + dc] > forest[row][col] && !visited[row + dr][col + dc])
        {
            if (maxDays[row + dr][col + dc] == 0)
            {
                visited[row + dr][col + dc] = true;
                maxDays[row + dr][col + dc] = maxSurvival(row + dr, col + dc);
                visited[row + dr][col + dc] = false;
            }
            else
                printf("skipped: %d \n", ++callCnt);
            
            if (maxDays[row + dr][col + dc] > maxFromHere && !checkPathOverlap(row + dr, col + dc))
            {
                offsetDir[row][col] = i;
                maxFromHere = maxDays[row + dr][col + dc];
            }
        }
    }
    ++maxFromHere;
    return maxFromHere;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    maxDay = 0;
    scanf("%d", &mapSize);

    for (int i = 0; i < mapSize; i++)
    {
        for (int j = 0; j < mapSize; j++)
        {
            scanf("%d", &forest[i][j]);
            maxDays[i][j] = 0;
            offsetDir[i][j] = -1;
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < mapSize; i++)
    {
        for (int j = 0; j < mapSize; j++)
        {
            if (maxDays[i][j] == 0)
                maxDays[i][j] = maxSurvival(i, j);
            maxDay = MAX(maxDay, maxDays[i][j]);
        }
    }

    printf("%d \n", maxDay);
}