#include <cstdio>
#include <memory.h>

int dp[1000001];

int minOps(int num)
{
    if (num == 1)
        return 0;
    
    if (dp[num] == 0)
    {
        int min_ops = __INT_MAX__;
        int op = 0;
        if (num % 3 == 0)
        {
            op = minOps(num / 3) + 1;
            min_ops = (op < min_ops ? op : min_ops);
        }
        if (num % 2 == 0)
        {
            op = minOps(num / 2) + 1;
            min_ops = (op < min_ops ? op : min_ops);
        }
        if (num > 1)
        {
            op = minOps(num - 1) + 1;
            min_ops = (op < min_ops ? op : min_ops);
        }

        dp[num] = min_ops;
    }
    return dp[num];
}

int main(void)
{
    memset(dp, '\0', 4000004);
    int num;
    scanf("%d", &num);
    printf("%d \n", minOps(num));
}