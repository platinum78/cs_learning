#include <cstdio>

#define NONE 0
#define ADD 1
#define DEL 2
#define MAX 3

struct Operation
{
    int type_;
    void *operation_;
};

Operation operations[300000];
int opCnt = 0;

struct AddOper
{
    int a;
    int b;
};

void addOperation(int a, int b)
{
    // printf("AddOper %d %d \n", a, b);
    AddOper *pOper = new AddOper;
    pOper->a = a;
    pOper->b = b;
    operations[opCnt].type_ = ADD;
    operations[opCnt].operation_ = (void*)pOper;
    opCnt++;
}

void delOperation(int idx)
{
    // printf("DelOper(%d) %d \n", idx, operations[idx].type_);
    operations[opCnt].type_ = DEL;
    operations[opCnt].operation_ = NULL;
    ++opCnt;

    if (operations[idx].type_ == ADD)
    {
        operations[idx].type_ = NONE;
        delete (AddOper*)operations[idx].operation_;
        operations[idx].operation_ = NULL;
    }
}

void maxOperation(int x)
{
    // printf("MaxOper(%d) %d \n", x, opCnt);
    operations[opCnt].type_ = MAX;
    AddOper *pOper;
    long maxNum = __LONG_MAX__ + 1;
    long lineNum;
    bool isEmpty = true;

    for (int i = 0; i < opCnt; i++)
    {
        if (operations[i].type_ == ADD)
        {
            isEmpty = false;
            pOper = (AddOper*)operations[i].operation_;
            lineNum = pOper->a * x + pOper->b;
            maxNum = (lineNum > maxNum ? lineNum : maxNum);
        }
    }

    if (isEmpty)
        printf("NO \n");
    else
        printf("%ld \n", maxNum);
    
    ++opCnt;
}

int main(void)
{
    freopen("input.txt", "r", stdin);

    int tcCnt, tcOpCnt;
    int opType, arg1, arg2;
    scanf("%d", &tcCnt);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        opCnt = 0;
        printf("#%d \n", tc);

        scanf("%d", &tcOpCnt);
        for (int op = 0; op < tcOpCnt; op++)
        {
            scanf("%d", &opType);
            if (opType == ADD)
            {
                scanf("%d %d", &arg1, &arg2);
                addOperation(arg1, arg2);
            }
            else if (opType == DEL)
            {
                scanf("%d", &arg1);
                delOperation(arg1 - 1);
            }
            else
            {
                scanf("%d", &arg1);
                maxOperation(arg1);
            }
        }
    }
}