#include <cstdio>

bool findMinOps_(int num, int ops_cnt, int *min_ops)
{
    if (num == 1)
    {
        if (ops_cnt < *min_ops)
            *min_ops = ops_cnt;
        return true;
    }

    if (num % 3 == 0)
        if (findMinOps_(num / 3, ops_cnt + 1, min_ops))
            return true;
    if (num % 2 == 0)
        if (findMinOps_(num / 2, ops_cnt + 1, min_ops))
            return true;
    if (findMinOps_(num - 1, ops_cnt + 1, min_ops))
        return true;
}

int main(void)
{
    int opsCnt = __INT_MAX__;
    int *pOpsCnt = &opsCnt;
    int num;
    scanf("%d", &num);

    findMinOps_(num, 0, pOpsCnt);

    printf("%d \n", opsCnt);
}