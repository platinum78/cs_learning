#include <iostream>
#include <cstdio>

int main(void)
{
    freopen("input.txt", "r", stdin);
    int tcCnt;
    int people, questions, score, totalScore;
    int firstPax, firstScore;
    std::cin >> tcCnt;

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        firstPax = firstScore = 0;
        std::cin >> people >> questions;

        for (int p = 0; p < people; p++)
        {
            score = totalScore = 0;
            for (int q = 0; q < questions; q++)
            {
                std::cin >> score;
                totalScore += score;
            }

            if (totalScore > firstScore)
            {
                firstPax = 1;
                firstScore = totalScore;
            }
            else if (totalScore == firstScore)
            {
                ++firstPax;
            }
        }

        std::cout << "#" << tc << " " << firstPax << " " << firstScore << std::endl;
    }
}