#include <iostream>

int addTwosComplementOK(int num1, int num2)
{
    if (num1 > 0 && num2 > 0 && num1 + num2 < 0)
        return 0;
    if (num1 < 0 && num2 < 0 && num1 + num2 > 0)
        return 0;
    return 1;
}

int main(void)
{
    
}