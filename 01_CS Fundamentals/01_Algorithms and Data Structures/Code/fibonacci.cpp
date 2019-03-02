#include <iostream>

int fibonacci(int idx, int num1, int num2)
{
    if (idx == 1)
        return num1;
    else if (idx == 2)
        return num2;
    return fibonacci(idx - 1, num1, num2) + fibonacci(idx - 2, num1, num2);
}

int main(void)
{
    for (int i = 1; i < 100; i++)
        std::cout << fibonacci(i, 1, 1) << std::endl;
}