#include <cstdio>
#define MAX(X, Y)   (X > Y ? X : Y)

int scores[301] = { 0, };
int maxScores[301][2] = { {0, 0}, };
int stairs;

int findScore(int pos, int single_steps)
{
    if (pos == stairs)
        return 0;

    int globalScore = 0;
    
    if (pos + 1 < stairs)
    {
        if (maxScores[pos + 1][0] == 0)
            maxScores[pos + 1][0] = findScore(pos + 1, 0);
        if (maxScores[pos + 1][1] == 0)
            maxScores[pos + 1][1] = findScore(pos + 1, 1);
    }
    if (pos + 2 < stairs)
    {
        if (maxScores[pos + 2][0] == 0)
            maxScores[pos + 2][0] = findScore(pos + 2, 0);
        if (maxScores[pos + 2][1] == 0)
            maxScores[pos + 2][1] = findScore(pos + 2, 1);
    }

    if (single_steps == 0)
    {
        globalScore = MAX(globalScore, maxScores[pos + 1][1]);
        globalScore = MAX(globalScore, maxScores[pos + 2][0]);
    }
    else if (single_steps == 1)
    {
        globalScore = MAX(globalScore, maxScores[pos + 2][0]);
    }

    return globalScore;
}

int main(void)
{
    scanf("%d", &stairs);
    for (int i = 1; i <= stairs; i++)
        scanf("%d", &scores[i]);
    printf("%d \n", findScore(0, -1));
}