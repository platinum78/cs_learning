#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

unsigned long long int biCoef(int a, int b)
{
    unsigned long long int num1 = a;
    unsigned long long int coef = 1;
    bool numDone = false;
    bool denDone = false;
    int denCnt = 0;
    std::vector<int> denominators(b);
    for (int i = 0; i < b; i++)
        denominators[i] = i + 1;
    while (!(numDone && denDone))
    {
        std::cout << coef << std::endl;
        if (num1 > a - b)
            coef *= (num1--);
        else
            numDone = true;

        for (int i = 0; i < denominators.size(); i++)
        {
            if (denominators[i] == 0)
                continue;

            if (coef >= denominators[i] && coef % denominators[i] == 0)
            {
                coef /= denominators[i];
                ++denCnt;
                denominators[i] = 0;
            }
        }
        if (denCnt == b)
            denDone = true;
    }

    return coef;
}

unsigned long long int findParComb(int openCnt, int closeCnt)
{
    if (openCnt == 0 || closeCnt == 0)
        return 1;
    unsigned long long int comb = biCoef(openCnt + closeCnt, openCnt);
    comb = comb - comb * openCnt / (closeCnt + 1);
    return comb;
}

void parenthesesWriter(int length, unsigned long long int num)
{
    int openCnt = length, closeCnt = length;
    unsigned long long int order = num - 1;     // Using 0-base indexing

    if (order >= findParComb(length, length))
    {
        std::cout << ")(";
        return;
    }

    std::string parString(2 * length, '\0');
    int strIdx = 0;
    int parity = openCnt - closeCnt;
    parString[strIdx++] = '(';
    --openCnt;
    
    int orderIfClose;
    while (openCnt + closeCnt > 0)
    {
        orderIfClose = findParComb(openCnt - 1, closeCnt);
        if (order < orderIfClose)
        {
            parString[strIdx++] = '(';
            --openCnt;
            if (openCnt == 0)
                for (; closeCnt > 0; closeCnt--)
                    parString[strIdx++] = ')';
        }
        else if (order == orderIfClose)
        {
            parString[strIdx++] = ')';
            for (; openCnt > 0; openCnt--)
                parString[strIdx++] = '(';
            for (; closeCnt > 0; closeCnt--)
                parString[strIdx++] = ')';
            break;
        }
        else
        {
            parString[strIdx++] = ')';
            order -= orderIfClose;
            --closeCnt;
        }
    }

    std::cout << parString;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int tcCnt, length, order;
    std::cin >> tcCnt;

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        std::cin >> length >> order;
        std::cout << "#" << tc << " ";
        parenthesesWriter(length, order);
        std::cout << std::endl;
    }
}