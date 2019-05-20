#include <iostream>
#include <list>
#include <vector>

#define MAX(X, Y)   (X > Y ? X : Y)
#define MIN(X, Y)   (X < Y ? X : Y)

typedef unsigned int uint32;

struct Factor
{
    uint32 factor;
    uint32 power;
};

void expandFactorList(std::vector<uint32> &primes, uint32 upper_bound)
{
    uint32 maxPrime = primes[primes.size() - 1];
    bool isPrime = true;

    maxPrime += (maxPrime % 2) + 1;
    while (maxPrime <= upper_bound)
    {
        for (int i = 0; i < primes.size(); i++)
        {
            if (maxPrime % primes[i] == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
        {
            primes.push_back(maxPrime);
            break;
        }

        maxPrime += (maxPrime % 2) + 1;
        isPrime = true;
    }

    for (int i = 0; i < primes.size(); i++)
        std::cout << primes[i] << "  ";
    std::cout << std::endl;
}

uint32 findGCD(std::vector<uint32> &primes, uint32 fact_, uint32 num_)
{
    uint32 fact = fact_;
    uint32 num = num_;

    // Factorize num
    std::list<Factor> factors;
    expandFactorList(primes, MAX(fact_, num_));
    int idx = 0;
    int power = 0;

    while (num > 1)
    {
        power = 0;
        while (num % primes[idx] == 0)
        {
            num /= primes[idx];
            ++power;
        }

        if (power > 0)
        {
            Factor f;
            f.factor = primes[idx];
            f.power = power;
            factors.push_back(f);
        }

        ++idx;
    }

    std::list<Factor>::iterator iter;
    for (iter = factors.begin(); iter != factors.end(); iter++)
        if ((*iter).power > 0)
            std::cout << "Factor: " << (*iter).factor << ", Power: " << (*iter).power << std::endl;
}

int main(void)
{
    std::vector<uint32> primes;
    primes.push_back(2);

    findGCD(primes, 10, 10);
}