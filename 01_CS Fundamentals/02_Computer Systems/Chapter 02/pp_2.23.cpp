#include <iostream>
#include "./byte_representation.cpp"

int fun1(unsigned word)
{
    return (int)((word << 24) >> 24);
}

int fun2(unsigned word)
{
    return ((int)word << 24) >> 24;
}

int main(void)
{
    int num1 = 0x00000076;
    int num2 = 0x87654321;
    int num3 = 0x000000C9;
    int num4 = 0xEDCBA987;

    show_int(fun1(num1));
    show_int(fun1(num2));
    show_int(fun1(num3));
    show_int(fun1(num4));

    show_int(fun2(num1));
    show_int(fun2(num2));
    show_int(fun2(num3));
    show_int(fun2(num4));
}