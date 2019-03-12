#include <stdio.h>

int main(void)
{
    unsigned long x = 0xFEDCBA9876543210;
    unsigned char y = x;
    printf("%lx, %x \n", x, y);
    return 0;
}