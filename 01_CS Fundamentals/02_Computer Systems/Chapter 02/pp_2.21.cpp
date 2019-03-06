#include <iostream>

int main(void)
{
    int num = -2147483647;
    bool eval = ((num - 1) == 2147483648U);
    std::cout << eval << std::endl;
}