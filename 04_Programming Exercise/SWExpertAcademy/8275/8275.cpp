#include <cstdio>

int population[7];
int records[10][3];
int N, X, M;
bool found;

void countCase();
void countCase_(int);
bool checkCond();

void countCase()
{
    for (int i = 1; i <= N; i++)
        population[i] = X;
    found = true;
    countCase_(0);
}

void countCase_(int idx)
{
    if (found)
        return;

    if (idx > N)
    {
        checkCond();
    }
    
    for (int i = 0; i)
}

int main(void)
{
    int tcCnt;
    scanf("%d", &tcCnt);


    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%d %d %d", &N, &X, &M);
        for (int m = 0; m < M; m++)
            scanf("%d %d %d", &records[m][0], &records[m][1], &records[m][2]);
    }
}
