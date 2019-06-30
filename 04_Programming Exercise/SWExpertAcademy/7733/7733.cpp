#include <cstdio>
#include <vector>
#include <list>

int cheese[100][100];
std::vector< std::list<int> > days;
int chunkCode = 0;
int cheeseSize;

bool isPointAvailable(int row, int col)
{
    if (row < 0 || row >= cheeseSize)
        return false;
    if (col < 0 || col >= cheeseSize)
        return false;
    if (cheese[row][col] == 0)
        return false;
    return true;
}

int markChunk(int row, int col, int num)
{

}

int main(void)
{
    int tcCnt;
    scanf("%d", &tcCnt);

    for (int tc = 0; tc <= tcCnt; tc++)
    {
        
    }
}