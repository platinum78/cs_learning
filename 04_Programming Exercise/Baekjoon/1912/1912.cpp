#include <cstdio>
int numAcc[100001] = { 0, };

int main(void)
{
    int n, num, acc = 0;
    int maxSum = -1000000000;
    int minAcc = 1000000000, maxAcc = -1000000000;
    int minIdx = 0, maxIdx = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &num);
        acc += num;
        numAcc[i] = acc;
        
        if (numAcc[i - 1] < minAcc)
        {
            minAcc = numAcc[i - 1];
            minIdx = i;
        }

        if (acc - minAcc > maxSum)
            maxSum = acc - minAcc;
    }

    printf("%d \n", maxSum);
}