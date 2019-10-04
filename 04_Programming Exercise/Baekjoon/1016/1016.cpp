#include <cstdio>
#include <cmath>
#include <memory.h>

bool *div_;

long findMinDiv(long lower_bound, long denominator)
{
    while (lower_bound % denominator != 0)
        lower_bound++;
    return lower_bound;
}

bool isSqrtLargerThan(long num)
{
    double num_ = long(sqrt(num));
    if (num_ * num_ == num)
        return true;
    return false;
}

int main(void)
{
    div_ = new bool[1000000];
    memset(div_, '\0', 1000000);
    long minNum, maxNum, range, diff, num, sq;
    scanf("%ld %ld", &minNum, &maxNum);

    num = long(sqrt(minNum));
    if (num * num != minNum)
        num += 1;

    num = (num >= 2 ? num : 2);
    sq = num * num;
    while (sq <= maxNum)
    {
        if (isSqrtLargerThan(sq))
            continue;
        for (long n = findMinDiv(minNum, sq); n <= maxNum; n += sq)
            div_[n - minNum] = true;
        num++;
        sq = num * num;
    }

    long nonDivCnt = 0;
    for (long i = minNum; i <= maxNum; i++)
        if (!div_[i - minNum])
            nonDivCnt++;
    
    printf("%ld \n", nonDivCnt);
}