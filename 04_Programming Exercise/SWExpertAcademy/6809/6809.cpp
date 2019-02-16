#include <iostream>
#include <vector>
#include <cstdio>

#define NORMAL 0
#define BACKWARD_BY_ONE 1
#define FORWARD_BY_ONE 2


int maxCharge(std::vector<int> &chargeMap, std::vector<int> &movedMap)
{
    if (chargeMap.size() <= 2)
        return chargeMap[chargeMap.size()-1];
    if (chargeMap.size() == 3)
    {
        if (chargeMap[1] > 0)
            return chargeMap[0] + chargeMap[2];
        else
            return chargeMap[2];
    }
    
    int thisCellCharge, nextCellCharge;
    int maxIdx = 0, startIdx = 0;
    bool reachedEnd = false;

    while (maxIdx < chargeMap.size())
    {
        std::cout << startIdx << std::endl;
        for (int maxIdx = startIdx; maxIdx < chargeMap.size()-2; maxIdx++)
        {
            if (movedMap[maxIdx+1] == 0)
            {
                movedMap[maxIdx] = chargeMap[maxIdx];
                movedMap[maxIdx+1] = chargeMap[maxIdx+1];
            }
            else
            {
                --movedMap[maxIdx+1];
                movedMap[maxIdx+2] += movedMap[maxIdx];
                movedMap[maxIdx] = chargeMap[maxIdx];
            }

            if (maxIdx == chargeMap.size() - 3)
                reachedEnd = true;
        }

        if (reachedEnd)
            break;
        
        ++startIdx;
    }

    return movedMap[movedMap.size()-1];
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    int tcCnt, cellCnt;
    std::vector<int> chargeMap;
    std::vector<int> movedMap;
    std::cin >> tcCnt;

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        std::cin >> cellCnt;
        chargeMap.resize(cellCnt);
        for (int c = 0; c < cellCnt; c++)
            std::cin >> chargeMap[c];
        movedMap = chargeMap;
        
        int maxEnergy = maxCharge(chargeMap, movedMap);
        std::cout << "#" << tc << " " << maxEnergy << std::endl;
    }

    return 0;
}