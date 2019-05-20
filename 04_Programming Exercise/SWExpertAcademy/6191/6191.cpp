#include <iostream>
#include <list>
#include <vector>

typedef unsigned long long uint64;

void findPrimes(std::vector<uint64> &primes, uint64 upper_bound)
{
    primes.resize(0);
    primes.push_back(2);

    int num = 3;
    bool isPrime = true;
    while (num <= upper_bound)
    {
        for (int i = 0; i < primes.size(); i++)
        {
            if (num % primes[i] == 0)
                isPrime = false;
            
            if (!isPrime)
                break;
        }

        if (isPrime)
            primes.push_back(num);
        
        num++;
        isPrime = true;
    }
}

uint64 combination(uint64 tot, uint64 sel)
{
    
}

int main(void)
{
    std::vector<uint64> primes;
    findPrimes(primes, 100);
}