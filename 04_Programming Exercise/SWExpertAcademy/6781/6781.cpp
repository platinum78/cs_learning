// SWExpertAcademy Problem #6781
// Quit due to error of problem.

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>

bool isCont(int n1, int n2, int n3)
{
    int num = 0;
    if (abs(n1 - n2) == 1)
        ++num;
    if (abs(n2 - n3) == 1)
        ++num;
    if (abs(n3 - n1) == 1)
        ++num;
    
    if (num == 2)
        return true;
    else
        return false;
}

bool isSatisfied(std::vector<std::vector<int>> &cardList)
{
    int num1 = -1, num2 = -1, num3 = -1;

    for (int c = 0; c < cardList.size(); c++)
    {
        for (int n = 0; n < cardList[c].size(); n++)
        {
            if (cardList[c][n] >= 10)
            {
                std::cout << "Three cards" << std::endl;
                return true;
            }
            if (cardList[c][n] > 0)
            {
                num3 = num2;
                num2 = num1;
                num1 = n + 1;
            }
            if (isCont(num1, num2, num3))
            {
                std::cout << "Continuous" << std::endl;
                return true;
            }
        }

        num1 = num2 = num3 = -1;
    }

    return false;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    std::vector<std::vector<int>> cardList(3, std::vector<int>(9, 0));
    int tcCnt, colorCode, number;
    std::string cardColors;
    std::string cardNumbers;
    
    std::cin >> tcCnt;
    
    for (int tc = 1; tc <= tcCnt; tc++)
    {
        std::cin >> cardNumbers;
        std::cin >> cardColors;

        for (int i = 0; i < cardList.size(); i++)
            for (int j = 0; j < cardList[i].size(); j++)
                cardList[i][j] = 0;

        for (int i = 0; i < 9; i++)
        {
            colorCode = (cardColors[i] == 'R' ? 0 : (cardColors[i] == 'G' ? 1 : 2));
            number = int(cardNumbers[i] - '0');
            ++cardList[colorCode][number];
        }
        
        if (isSatisfied(cardList))
            std::cout << "#" << tc << " Win" << std::endl;
        else
            std::cout << "#" << tc << " Continue" << std::endl;
    }

    return 0;
}