#include <iostream>
#include <vector>
#include <list>
#include <cstdio>

struct Core
{
    int row;
    int col;
};

int main(void)
{
    int tcCnt;
    int mapSize;
    fscanf(stdin, "%d", &tcCnt);
    int circuitMap[12][12];
    std::vector<Core> cores;
    std::vector<int> minWireLen;
    
    for (int tc = 1; tc <= tcCnt; tc++)
    {
        // Get map size and map data.
        fscanf(stdin, "%d", &mapSize);
        cores.resize(0);
        for (int i = 0; i < mapSize; i++)
        {
            for (int j = 0; j < mapSize; j++)
            {
                fscanf(stdin, "%d", &circuitMap[i][j]);
                if (circuitMap[i][j] == 1)
                    cores.push_back((Core){ i, j });
            }
        }
        minWireLen.resize(cores.size() + 1);
    }
}