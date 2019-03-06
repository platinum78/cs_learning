#include <cstdio>

int main(void)
{
    unsigned char num[5] = { 0x1, 0x4, 0x7, 0xA, 0xE };

    for (int i = 0; i < 5; i++)
        printf("Original: %u, Negation: %u \n", num[i], ~num[i]);
}