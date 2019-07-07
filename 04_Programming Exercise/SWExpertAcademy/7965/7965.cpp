#include <cstdio>
#include <cmath>
#define DIV 1000000007

long modPower(long x)
{
    long coef = 1, num = x, mul = 0, rem = 1, rem_total = 1;
    long x_ = 0;
    while (num > 0)
    {
        mul = num % 2;
        num /= 2;
        rem = x % DIV;

        if (mul)
        {
            for (int i = 0; i < coef - 2; i++)
            {
                rem = (rem * rem) % DIV;
            }
            x_ += pow(2, coef - 1);
        }
        rem_total = (rem_total * rem) % DIV;
        coef++;
    }

    printf("%lu \n", x_);

    return rem_total;
}

int main(void)
{
    freopen("input.txt", "r", stdin);

    int tcCnt;
    long maxNum, num;
    scanf("%d", &tcCnt);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%lu", &maxNum);
        printf("#%d %lu \n", tc, modPower(maxNum));
    }
}