#include <cstdio>
#include <memory.h>

struct Operation
{
    int type;
    int arg1;
    int arg2;
};

Operation *operations[300001];

void opType1(int op_ord)
{
    Operation *pOper = new Operation;
    pOper->type = 1;
    scanf("%d %d", &(pOper->arg1), &(pOper->arg2));
    operations[op_ord] = pOper;
}

void opType2(int op_ord)
{
    Operation *pOper = new Operation;
    pOper->type = 2;
    int del_ord;
    scanf("%d", &del_ord);
    pOper->arg1 = del_ord;
    pOper->arg2 = -1;
    delete operations[del_ord];
}

void opType3(int op_ord)
{
    Operation *pOper = new Operation;
    pOper->type = 3;
    int num; scanf("%ld", &num);
    long testNum, maxNum = 0x8000000000000000;
    int max_bound = op_ord - 1;
    int numPairs = 0;
    for (int i = 1; i <= max_bound; i++)
    {
        if (operations[i] != NULL && operations[i]->type == 1)
        {
            ++numPairs;
            testNum = operations[i]->arg1 * long(num) + operations[i]->arg2;
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

    for (int i = 0; i < 300001; i++)
        operations[i] = NULL;

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

        for (int i = 1; i <= opCnt; i++)
        {
            delete operations[i];
            operations[i] = NULL;
        }
    }
}