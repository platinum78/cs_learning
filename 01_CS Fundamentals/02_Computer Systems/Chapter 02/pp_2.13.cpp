#include <cstdio>

int bis(int x, int m)
{
    return x | m;
}

int bic(int x, int m)
{
    printf("%x \n", ~m);
    return x & ~m;
}

int main(void)
{
    printf("%x \n", bis(0xFFFFFFFF, 0x0F0F0F0F));
    printf("%x \n", bic(0xFFFFFFFF, 0x0F0F0F0F));
}