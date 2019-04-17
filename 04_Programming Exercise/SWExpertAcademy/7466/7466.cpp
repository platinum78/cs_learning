#include <iostream>
#include <list>
#include <cstdio>

struct prime
{
    long num;
    int population;
};

prime *makeNewPrime(long num_)
{
    prime *pPrime = new prime;
    pPrime->num = num_;
    pPrime->population = 0;
    return pPrime;
}

void PrimeFinder(std::list<prime*> &primes, long upperBound)
{
    std::list<prime*>::iterator iter;
    long testNum;
    if (primes.empty())
        testNum = 2;
    else
        testNum = (primes.back()->num) + 1;
    std::cout << testNum << std::endl;
    bool isPrime;

    while (testNum * testNum <= upperBound)
    {
        std::cout << "here" << std::endl;
        isPrime = true;
        for (iter = primes.begin(); iter != primes.end(); iter++)
        {
            if (testNum % (*iter)->num == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            primes.push_back(makeNewPrime(testNum));
        testNum++;
    }
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    
    int tcCnt, num;
    std::cin >> tcCnt;
    std::list<prime*> primes;
    PrimeFinder(primes, num);
    std::list<prime*>::iterator iter;
    for (iter = primes.begin(); iter != primes.end(); iter++)
        std::cout << (*iter)->num << std::endl;

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        std::cin >> num;
    }
    
    return 0;
}