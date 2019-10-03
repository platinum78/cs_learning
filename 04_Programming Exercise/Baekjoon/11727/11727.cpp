#include <cstdio>

int dp[1001];

int main(void)
{
    int len;
    scanf("%d", &len);

    dp[1] = 1;
    dp[2] = 3;

    for (int i = 3; i <= len; i++)
        dp[i] = (2 * dp[i - 2] + dp[i - 1]) % 10007;
    
    printf("%d \n", dp[len]);
}