#include <cstdio>

int maskLSB(int val)
{
    return val & 0xFF;
}

int flipExceptLSB(int val)
{
    return (val ^ 0xFFFFFFFF) ^ 0xFF;
}

int lsbToOne(int val)
{
    return val | 0xFF;
}

int main(void)
{
    printf("%x \n", maskLSB(0x87654321));
    printf("%x \n", flipExceptLSB(0x87654321));
    printf("%x \n", lsbToOne(0x87654321));
}