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

void mergeFactors(std::list<prime*> &factor1, std::list<prime*> &factor2)
{
    std::list<prime*>::iterator iter1 = factor1.begin(), iter2 = factor2.begin();
    bool factor1Exhausted = false, factor2Exhausted = false;

    while (!factor2Exhausted)
    {
        while (iter1 != factor1.end() && (*iter1)->num < (*iter2)->num)
            iter1++;

        if (iter1 != factor1.end() && (*iter1)->num == (*iter2)->num)
            (*iter1)->population += (*iter2)->population;
        else
            factor1.insert(iter1, *iter2);
        iter2++;
        if (iter2 == factor2.end())
            factor2Exhausted = true;
    }
}

long sectFactors(std::list<prime*> &factor1, std::list<prime*> &factor2, std::list<prime*> &factorSection)
{
    std::list<prime*>::iterator iter1 = factor1.begin(), iter2 = factor2.begin(), iterSect = factorSection.begin();
    factorSection.resize(0);
    bool factor1Exhausted = false, factor2Exhausted = false;

    while (!factor2Exhausted)
    {
        while (iter1 != factor1.end() && (*iter1)->num < (*iter2)->num)
            iter1++;

        if (iter1 != factor1.end() && (*iter1)->num == (*iter2)->num)
            factorSection.push_back(makeNewPrime((*iter1)->num, MIN((*iter1)->population, (*iter2)->population)));
        iter2++;
        if (iter2 == factor2.end())
            factor2Exhausted = true;
    }

    long gcd = 1;
    for (iterSect = factorSection.begin(); iterSect != factorSection.end(); iterSect++)
        for (int p = 0; p < (*iterSect)->population; p++)
            gcd *= (*iterSect)->num;
    
    return gcd;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    std::list<prime*> factorK;
    std::list<prime*> factorN1;
    std::list<prime*> factorN2;
    std::list<prime*> factorSection;

    int tcCnt, N, K;
    std::cin >> tcCnt;
    for (int tc = 1; tc <= tcCnt; tc++)
    {
        std::cin >> N >> K;
        factorize(factorK, K);
        factorize(factorN1, 1);
        for (int i = 2; i <= N; i++)
        {
            factorize(factorN2, i);
            mergeFactors(factorN1, factorN2);
        }

        long gcd = sectFactors(factorN1, factorK, factorSection);
        std::cout << "#" << tc << " " << gcd << std::endl;
    }
    return 0;
}