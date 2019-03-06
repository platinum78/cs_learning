#include <iostream>

int uAddOK(unsigned x, unsigned y)
{
    if (y > ~x)
        return 0;
    else
        return 1;
}

int main(void)
{
    int num1 = 0x0F0F0F0F;
    int num2 = ~num1;

    std::cout << uAddOK(num1, num2 - 1) << " " << uAddOK(num1, num2) << std::endl;
}