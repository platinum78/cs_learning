#include <cstdio>
#include <memory.h>
#define MOD 1000000000

int dpTable[101][10][1 << 10];

int findNum(int len, int digit, int inclusion)
{
    if (digit < 0 || digit > 9)
        return 0;
    if (len == 1)
        return (1 << digit | inclusion) == 1023;
    int &num = dpTable[len][digit][inclusion];
    if (num != -1)
        return num;

    inclusion |= (1 << digit);
    num = (findNum(len - 1, digit - 1, inclusion) +
           findNum(len - 1, digit + 1, inclusion)) % MOD;
    return num;
}

int main(void)
{
    freopen("input.txt", "r", stdin);

    int tcCnt, tcLen, tcMatchCnt;
    scanf("%d", &tcCnt);
    memset(dpTable, -1, sizeof(dpTable));

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%d", &tcLen);
        tcMatchCnt = 0;
        for (int digit = 1; digit <= 9; digit++)
            tcMatchCnt = (tcMatchCnt + findNum(tcLen, digit, 0)) % MOD;
        printf("#%d %d \n", tc, tcMatchCnt);
    }

    return 0;
}