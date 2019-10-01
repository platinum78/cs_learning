#include <cstdio>
#define MAX(X, Y)   (X > Y ? X : Y)

int scores[301] = { 0, };
int maxScores[301][2] = { {0, 0}, };
int stairs;

int findScore(int pos, int single_steps)
{
    if (pos >= stairs)
        return 0;
    if (single_steps == 2)
        return 0;

    int globalScore = 0;
    
    

    return globalScore;
}

int main(void)
{
    scanf("%d", &stairs);
    for (int i = 1; i <= stairs; i++)
        scanf("%d", &scores[i]);
    printf("%d \n", findScore(0, -1));
}