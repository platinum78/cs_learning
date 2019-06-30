#include <cstdio>
#include <memory.h>

struct Operation
{
    int type;
    int arg1;
    int arg2;
};

int operations[300001][3];

void opType1(int op_ord)
{
    operations[op_ord][0] = 1;
    scanf("%d %d", &operations[op_ord][1], &operations[op_ord][2]);
}

void opType2(int op_ord)
{
    operations[op_ord][0] = 2;
    int del_ord;
    scanf("%d", &del_ord);
    operations[op_ord][1] = del_ord;
    operations[del_ord][0] *= -1;
}

void opType3(int op_ord)
{
    operations[op_ord][0] = 3;
    int num; scanf("%ld", &num);
    long testNum, maxNum = 0x8000000000000000;
    int max_bound = op_ord - 1;
    int numPairs = 0;
    for (int i = 1; i <= max_bound; i++)
    {
        if (operations[i][0] == 1)
        {
            ++numPairs;
            testNum = operations[i][1] * long(num) + operations[i][2];
            if (testNum > maxNum)
                maxNum = testNum;
        }
    }

    if (numPairs)
        printf("%ld \n", maxNum);
    else
        printf("NO \n");
}

int main(void)
{
    freopen("input.txt", "r", stdin);

    int tcCnt, opCnt, opType;
    scanf("%d", &tcCnt);
    
    for (int tc = 1; tc <= tcCnt; tc++)
    {
        printf("#%d \n", tc);
        scanf("%d", &opCnt);

        for (int i = 1; i <= opCnt; i++)
        {
            scanf("%d", &opType);
            switch (opType)
            {
            case 1:
                opType1(i);
                break;
            case 2:
                opType2(i);
                break;
            case 3:
                opType3(i);
                break;
            };
        }
    }
}