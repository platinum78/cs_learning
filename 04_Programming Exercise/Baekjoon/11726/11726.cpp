#include <cstdio>

int tileFilling[1001] = { 0, };

int main(void)
{
    int n;
    scanf("%d", &n);
    tileFilling[0] = 0;
    tileFilling[1] = 1;
    tileFilling[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        tileFilling[i] = (tileFilling[i - 1] + tileFilling[i - 2]) % 10007;
    }

    printf("%d \n", tileFilling[n]);
    return 0;
}