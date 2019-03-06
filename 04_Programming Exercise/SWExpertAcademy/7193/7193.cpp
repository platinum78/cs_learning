#include <iostream>
#include <cstdio>
#include <ctype.h>

int main(void)
{
    freopen("input.txt", "r", stdin);
    int tcCnt;
    int denominator;
    int numDigit;
    int remainderSum = 0;
    char charBuf;
    std::cin >> tcCnt;

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        remainderSum = 0;
        std::cin >> denominator;
        
        charBuf = getchar();
        while (!isdigit(charBuf))
            charBuf = getchar();

        while (isdigit(charBuf))
        {
            numDigit = charBuf - '0';
            remainderSum += numDigit;
            charBuf = getchar();
        }

        std::cout << "#" << tc << " " << remainderSum % (denominator - 1) << std::endl;
    }
}