#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

int main(void)
{
    freopen("input.txt", "r", stdin);

    int tcCnt;
    int boxCnt, boxWeight;
    int heavyIdx, lightIdx, iteration;
    int stackSize, stackWeight, stackCnt;
    bool movedAll;
    std::vector<int> boxes;

    fscanf(stdin, "%d", &tcCnt);
    for (int tc = 1; tc <= tcCnt; tc++)
    {
        fscanf(stdin, "%d", &boxCnt);
        boxes.resize(boxCnt);

        for (int i = 0; i < boxCnt; i++)
            fscanf(stdin, "%d", &boxes[i]);
        
        std::sort(boxes.begin(), boxes.end());
        lightIdx = 0;
        heavyIdx = (int)boxes.size() - 1;
        
        stackCnt = 0;
        movedAll = false;
        while (!movedAll)
        {
            stackWeight = 0;
            fprintf(stdout, "%d \n", boxes[heavyIdx]);
            boxWeight = boxes[heavyIdx--];

            stackWeight += boxWeight;
            while (stackWeight < 50)
            {
                if (lightIdx > heavyIdx)
                {
                    movedAll = true;
                    break;
                }
                stackWeight += boxWeight;
                ++lightIdx;
            }
            
            ++stackCnt;
        }

        if (stackWeight < 50)
            --stackCnt;
        
        fprintf(stdout, "#%d %d \n", tc, stackCnt);
    }
}