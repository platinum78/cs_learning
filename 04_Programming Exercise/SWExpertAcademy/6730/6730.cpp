#include <iostream>
#include <vector>

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main(void)
{
    std::vector<int> heights;
    int ascend, descend;
    int maxAscend = 0, minDescend = 0;
    int tcCnt, obstacleCnt;
    std::cin >> tcCnt;

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        ascend = descend = maxAscend = minDescend = 0;
        std::cin >> obstacleCnt;
        heights.resize(obstacleCnt);

        for (int i = 0; i < obstacleCnt; i++)
            std::cin >> heights[i];
        
        for (int i = 0; i < obstacleCnt - 1; i++)
        {
            if (heights[i] < heights[i+1])
                ascend = heights[i+1] - heights[i];
            else
                descend = heights[i+1] - heights[i];
            
            maxAscend = max(maxAscend, ascend);
            minDescend = min(minDescend, descend);
        }
        std::cout << "#" << tc << " " << maxAscend << " " << -minDescend << std::endl;
    }

    return 0;
}