#include <cstdio>

int recursiveSum(int num)
{
    int a, b, c;
    if (!num)
        return 0;
    
    return 1 + recursiveSum(num - 1);
}

int iterativeSum(int num)
{
    int num_ = 0;
    while (num > 0)
    {
        num_++;
        num--;
    }
    return num_;
}

int main(void)
{
    printf("%d \n", iterativeSum(100000));
    printf("%d \n", recursiveSum(100000));
}