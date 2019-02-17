// SWExpertAcademy Problem #6808
// Start: 16 FEB 2019, 13:44

#include <iostream>
#include <vector>
#include <cstdio>

class Solver
{
  private:
    std::vector<int> kyCards;
    std::vector<int> iyCards;
    std::vector<int> iyCardsOrdered;
    int kyScore = 0;
    int iyScore = 0;
    int gameRound = 9;

  public:
    Solver();
    void cardInit();
    bool doesKyHave(int num);
    int findKyWin();
};

Solver::Solver()
{
    kyCards.resize(9);
    iyCards.resize(9);
    iyCardsOrdered.resize(9, 0);
    std::cout << "Initialized!" << std::endl;
}

void Solver::cardInit()
{
    for (int i = 0; i < 9; i++)
        std::cin >> kyCards[i];

    int idx = 0;
    for (int num = 1; num <= 18; num++)
        if (!doesKyHave(num))
            iyCards[idx++] = num;
}

bool Solver::doesKyHave(int num)
{
    for (int i = 0; i < kyCards.size(); i++)
        if (num == kyCards[i])
            return true;
    return false;
}

int Solver::findKyWin()
{
    // std::cout << "checkpoint" << std::endl;
    if (gameRound == 0)
    {
        kyScore = iyScore = 0;
        for (int i = 0; i < 9; i++)
        {
            if (kyCards[i] > iyCards[i])
                kyScore += kyCards[i] + iyCards[i];
            else
                iyScore += kyCards[i] + iyCards[i];
        }
        if (kyScore > iyScore)
            return 1;
        else
            return 0;
    }

    int kyWin = 0;
    int iyCard;
    for (int i = 0; i < iyCards.size(); i++)
    {
        if (iyCards[i] == 0)
            continue;

        iyCard = iyCards[i];
        iyCardsOrdered[9 - gameRound] = iyCard;
        iyCards[i] = 0;
        --gameRound;
        kyWin += findKyWin();
        ++gameRound;
        iyCards[i] = iyCard;
    }

    return kyWin;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    int tcCnt = 0, idx = 0, kyWin;
    Solver solver;
    std::vector<int> kyCards(9);
    std::vector<int> iyCards(9);
    std::cin >> tcCnt;

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        solver.cardInit();

        int kyWin = solver.findKyWin();
        std::cout << "#" << tc << " " << kyWin << std::endl;
    }
}