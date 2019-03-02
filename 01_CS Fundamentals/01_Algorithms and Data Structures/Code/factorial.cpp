#include <iostream>

int factorial(int n)
{
    if (n == 1)
        return n;
    
    return n * factorial(n - 1);
}

int main(void)
{
    std::cout << factorial(10) << std::endl;
}