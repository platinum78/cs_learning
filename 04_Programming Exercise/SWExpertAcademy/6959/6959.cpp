#include <iostream>
#include <vector>
#include <cstdio>
#include <string>

int roundFinder(std::vector<int> &gameNum)
{
    int leftIdx = 0;
    int digitTen, digitOne;
    int gameRound = 0;
    while (leftIdx < gameNum.size() - 1)
    {
        ++gameRound;
        digitTen = gameNum[leftIdx] + gameNum[leftIdx+1];
        digitOne = digitTen % 10;
        digitTen /= 10;

        if (digitTen > 0)
        {
            gameNum[leftIdx] = digitTen;
            gameNum[leftIdx+1] = digitOne;
        }
        else
        {
            gameNum[leftIdx+1] = digitOne;
            ++leftIdx;
        }
    }
    return gameRound;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    int tcCnt;
    std::vector<int> gameNum;
    std::string gameNumBuf;
    int gameRound = 0;
    std::cin >> tcCnt;

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        std::cin >> gameNumBuf;
        
        gameNum.resize(gameNumBuf.length());
        for (int i = 0; i < gameNum.size(); i++)
            gameNum[i] = gameNumBuf[i] - '0';

        gameRound = roundFinder(gameNum);

        if (gameRound % 2)
            std::cout << "#" << tc << " " << "A" << std::endl;
        else
            std::cout << "#" << tc << " " << "B" << std::endl;
    }

    return 0;
}