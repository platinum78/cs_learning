#include <cstdio>
long pinaryNumbers[2][91];

int main(void)
{
    for (int i = 0; i <= 90; i++)
        pinaryNumbers[0][i] = pinaryNumbers[1][i] = 0;

    int num;
    scanf("%d", &num);
    
    pinaryNumbers[0][1] = pinaryNumbers[1][1] = 1;

    for (int i = 2; i <= num; i++)
    {
        pinaryNumbers[0][i] = pinaryNumbers[0][i - 1] + pinaryNumbers[1][i - 1];
        pinaryNumbers[1][i] = pinaryNumbers[0][i - 1];
    }

    printf("%ld \n", pinaryNumbers[1][num]);
}