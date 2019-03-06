#include <cstdio>

int equal(int x, int y)
{
    return !(x ^ y);
}

int main(void)
{
    unsigned int uInt = 0xFFFFFFFF;
    int sInt = 0x80000000;
    printf("%u \n", uInt);
    printf("%x \n", sInt);
}