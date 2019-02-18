// SWExpertAcademy Problem #6809
// Begin: 18 FEB 2019, 19:20

#include <iostream>
#include <vector>
#include <cstdio>

int findMaxCharge(std::vector<int>& chargeMap, std::vector<int>& rechargedMap)
{
    if (chargeMap.size() == 1)
        return chargeMap[0];
    if (chargeMap.size() == 2)
        return chargeMap[1];
    if (chargeMap.size() == 3)
    {
        if (chargeMap[1] > 0)
            return chargeMap[0] + chargeMap[2];
        else
            return chargeMap[2];
    } 

    bool reachedEnd;
    for (int j = 0; j < chargeMap.size() - 2; j++)
    {
        reachedEnd = true;
        for (int i = j; i < chargeMap.size() - 2; i++)
        {
            // std::cout << i << std::endl;
            if (rechargedMap[i + 1] == 0)
            {
                rechargedMap = chargeMap;
                reachedEnd = false;
                break;
            }

            if (rechargedMap[i] == 0)
                continue;
            
            --rechargedMap[i + 1];
            rechargedMap[i + 2] += rechargedMap[i];
        }
        
        if (reachedEnd)
            break;
    }
    return rechargedMap[rechargedMap.size() - 1];
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    int tcCnt, cellCnt;
    std::cin >> tcCnt;
    std::vector<int> chargeMap;
    std::vector<int> rechargedMap;

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        std::cin >> cellCnt;
        chargeMap.resize(cellCnt);
        rechargedMap.resize(cellCnt);

        for (int i = 0; i < cellCnt; i++)
        {
            std::cin >> chargeMap[i];
            rechargedMap[i] = chargeMap[i];
        }

        std::cout << "#" << tc << " " << findMaxCharge(chargeMap, rechargedMap) << std::endl;
    }
}