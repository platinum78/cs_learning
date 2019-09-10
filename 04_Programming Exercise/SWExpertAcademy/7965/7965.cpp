#include <cstdio>
#include <cmath>
#define DIV 1000000007

int *refTable;

unsigned long modPower(unsigned long x, unsigned long pow)
{
    if (pow == 0)
        return 1;

    unsigned long x_, pow_half;
    pow_half = pow / 2;
    x_ = modPower(x, pow_half);
    x_ = (x_ * x_) % DIV;
    if (pow % 2)
        x_ = (x_ * x) % DIV;

    return x_;
}


int main(void)
{
    freopen("input.txt", "r", stdin);

    int tcCnt;
    unsigned long maxNum = 0, num, sum;
    refTable = new int[1000001];
    scanf("%d", &tcCnt);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%lu", &num);
        while (maxNum < num)
        {
            maxNum++;
            refTable[maxNum] = modPower(maxNum, maxNum);
        }
        
        sum = 0;
        for (int i = 1; i <= num; i++)
            sum = (sum + refTable[i]) % DIV;
        
        printf("#%d %lu \n", tc, sum);
    }
}