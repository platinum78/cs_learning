#include <iostream>
#include <list>
#include <cstdio>
#include <cmath>

#define MIN(X, Y) ( X < Y ? X : Y )
#define MAX(X, Y) ( X > Y ? X : Y )

struct prime
{
    long num;
    int population;
};

prime *makeNewPrime(long num_, int population_)
{
    prime *pPrime = new prime;
    pPrime->num = num_;
    pPrime->population = population_;
    return pPrime;
}

void factorize(std::list<prime*> &factor, int num_)
{
    factor.resize(0);
    factor.push_back(makeNewPrime(1, 0));
    long testNum = 2, num = num_, divnum = num_;
    int population;
    std::list<prime*>::iterator iter;
    bool isPrime;

    while (testNum * testNum < num)
    {
        isPrime = true;
        iter = factor.begin(); iter++;
        for (; iter != factor.end(); iter++)
        {
            if (testNum % (*iter)->num == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
        {
            population = 0;
            while (divnum % testNum == 0)
            {
                ++population;
                divnum /= testNum;
            }
            if (population > 0)
                factor.push_back(makeNewPrime(testNum, population));
        }

        ++testNum;
    }

    if (divnum > 1)
        factor.push_back(makeNewPrime(divnum, 1));
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    std::list<prime*> factorK;
    std::list<prime*> factorGCD;

    std::list<prime*>::iterator iterK;

    int tcCnt, N, K, num;
    long gcd;
    std::cin >> tcCnt;
    for (int tc = 1; tc <= tcCnt; tc++)
    {
        std::cin >> N >> K;
        factorize(factorK, K);

        gcd = 1;
        for (int i = 2; i <= N; i++)
        {
            num = i;
            iterK = factorK.begin();
            iterK++;
            for (; iterK != factorK.end(); iterK++)
            {
                while (num % (*iterK)->num == 0 && (*iterK)->population > 0 && num > 1)
                {
                    gcd *= (*iterK)->num;
                    num /= (*iterK)->num;
                    ((*iterK)->population)--;
                    // std::cout << gcd << std::endl;
                }
            }
        }
        
        std::cout << "#" << tc << " " << gcd << std::endl;
    }
    return 0;
}