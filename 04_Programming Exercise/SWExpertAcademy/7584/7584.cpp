#include <iostream>
#include <cstdio>

unsigned long minInclude(unsigned long num)
{
    unsigned long p2 = 0;
    while (p2 < num)
        p2 = 2 * p2 + 1;
    return p2;
}

bool digitTrace(unsigned long digit, unsigned long min_include)
{
    if (min_include == 1)
        return 0;

    bool data;
    if (digit < (min_include + 1) / 2)
        return digitTrace(digit, (min_include - 1) / 2);
    else if (digit > (min_include + 1) / 2)
        return !digitTrace(min_include - digit + 1, (min_include - 1) / 2);
    else
        return false;
}

int main(void)
{
    freopen("input.txt", "r", stdin);

    int tcCnt, tcQuestionCnt;
    std::cin >> tcCnt;
    unsigned long num;

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        std::cin >> num;
        std::cout << "#" << tc << " " << int(digitTrace(num, minInclude(num))) << std::endl;
    }

    return 0;
}