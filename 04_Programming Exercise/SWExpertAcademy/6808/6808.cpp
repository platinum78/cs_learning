// SWExpertAcademy Problem #6808
// Start: 16 FEB 2019, 13:44

#include <iostream>
#include <vector>
#include <cstdio>

bool isIncluded(std::vector<int> arr, int val)
{
    for (int i = 0; i < arr.size(); i++)
        if (val == arr[i])
            return true;
    return false;
}

int findKyWin(std::vector<int> &kyCards, std::vector<int> &iyCards,
              int kyScore, int iyScore, int gameRound)
{
    // std::cout << "checkpoint" << std::endl;
    if (gameRound == 0)
    {
        if (iyScore < kyScore)
            return 1;
        else
            return 0;
    }

    int kyNewScore = kyScore;
    int iyNewScore = iyScore;

    int kyWin = 0;
    int iyCard;
    for (int i = 0; i < iyCards.size(); i++)
    {
        if (iyCards[i] < 0)
            continue;
        
        if (kyCards[kyCards.size()-gameRound] < iyCards[i])
            iyNewScore += kyCards[kyCards.size()-gameRound] + iyCards[i];
        else if (iyCards[i] < kyCards[kyCards.size()-gameRound])
            kyNewScore += kyCards[kyCards.size()-gameRound] + iyCards[i];
        iyCard = iyCards[i];
        iyCards[i] = -1;
        kyWin += findKyWin(kyCards, iyCards, kyNewScore, iyNewScore, gameRound - 1);
        iyCards[i] = iyCard;
    }

    return kyWin;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    int tcCnt = 0, idx = 0, kyWin;
    std::vector<int> kyCards(9);
    std::vector<int> iyCards(9);
    std::cin >> tcCnt;

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        for (int i = 0; i < 9; i++)
            std::cin >> kyCards[i];

        idx = 0;
        for (int num = 1; num <= 18; num++)
            if (!isIncluded(kyCards, num))
                iyCards[idx++] = num;
        
        int kyWin = findKyWin(kyCards, iyCards, 0, 0, 9);
        std::cout << "#" << tc << " " << kyWin << std::endl;
    }
}