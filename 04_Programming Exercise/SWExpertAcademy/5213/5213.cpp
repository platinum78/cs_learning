#include <iostream>
#include <cstdio>
#include <cmath>
#include <list>

#define PRIME_SEARCH_MAX 1000000

void findPrime(std::list<unsigned long> &primes, unsigned long prime_max)
{
    int primeMax = sqrt(prime_max);
    bool isPrime = true;
    primes.push_back(2);
    std::list<unsigned long>::iterator iter;
    iter = primes.begin();
    
    for (unsigned long i = 3; i <= primeMax; i++)
    {
        isPrime = true;
        for (iter = primes.begin(); iter != primes.end(); iter++)
            if (i % (*iter) == 0)
            {
                isPrime = false;
                break;
            }
        if (isPrime)
            primes.push_back(i);
    }
}

unsigned long oddify(unsigned long num)
{
    unsigned long odd = num;
    while (num % 2 == 0)
        num /= 2;
    return num;
}

unsigned long f(std::list<unsigned long> &primes, unsigned long x)
{
    unsigned long num = x;
    unsigned long factor = 0, factorSum = 0, factorProd = 1;
    std::list<unsigned long>::iterator iter = primes.begin();
    iter++;

    while (*iter <= x)
    {
        std::cout << *iter << std::endl;
        factor = 1;
        factorSum = 0;

        while (num % (*iter) == 0)
        {
            factorSum += factor;
            factor *= (*iter);
            num /= (*iter);
        }
        factorSum += factor;
        factorProd *= factorSum;
        iter++;
    }

    printf("%lu \n", factorProd);
    return factorProd;
}

unsigned long fSum(std::list<unsigned long> &primes, unsigned long L, unsigned long R)
{
    unsigned long sum = 0;
    for (unsigned long i = L; i <= R; i++)
    {
        sum += f(primes, i);
        // printf("%lu \n", sum);
    }
    return sum;
}

int main(void)
{
    freopen("input.txt", "r", stdin);

    int tcCnt;
    unsigned long L, R;
    std::cin >> tcCnt;
    std::list<unsigned long> primes;
    findPrime(primes, PRIME_SEARCH_MAX);
    
    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%lu %lu \n", &L, &R);
        printf("#%d %lu \n", tc, fSum(primes, L, R));
    }
}
