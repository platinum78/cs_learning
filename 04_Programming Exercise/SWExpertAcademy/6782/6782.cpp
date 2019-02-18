// SWExpertAcademy Problem #6782
// Begin: 18 FEB 2019, 17:40

#include <iostream>
#include <cstdio>
#include <cmath>
#define AUTO -1

unsigned long long int findMaxSmallerSqrt(unsigned long long int num, unsigned long long int left_ = 1, unsigned long long int right_ = AUTO)
{
    unsigned long long int left = left_;
    unsigned long long int right = 0;
    if (right_ == AUTO)
        right = num;
    else
        right = right_;

    if (right - left == 1 || right - left == 0)
        return left;
    unsigned long long int center = (left + right) / 2;
    unsigned long long int cSquare = center * center;
    // std::cout << cSquare << std::endl;
    if (num > cSquare)
        return findMaxSmallerSqrt(num, center, right);
    else if (num < cSquare)
        return findMaxSmallerSqrt(num, left, center);
    else
        return center;
}

unsigned long long int findMinManipulation(unsigned long long int num)
{
    unsigned long long int manipCnt = 0;
    unsigned long long int sqrtNum;
    unsigned long long int manipNum = num;
    while (manipNum != 2)
    {
        sqrtNum = findMaxSmallerSqrt(manipNum);
        if (sqrtNum != manipNum)
        {
            manipCnt += (sqrtNum + 1) * (sqrtNum + 1) - manipNum;
            manipNum = sqrtNum + 1;
        }
        else
            manipNum = sqrtNum;
        ++manipCnt;
    }

    return manipCnt;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    int tcCnt;
    unsigned long long int initNum;
    std::cin >> tcCnt;

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        std::cin >> initNum;
        std::cout << "#" << tc << " " << findMinManipulation(initNum) << std::endl;
    }
}
