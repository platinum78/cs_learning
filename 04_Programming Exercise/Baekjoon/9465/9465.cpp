#include <cstdio>

#define MAX(X, Y)   (X > Y ? X : Y)

int stickers[300001][2];
int maxScores[300001][3];

int main(void)
{
    int tcCnt, stickerCnt;
    scanf("%d", &tcCnt);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%d", &stickerCnt);
        for (int i = 1; i <= stickerCnt; i++)
            scanf("%d", &stickers[i][0]);
        for (int i = 1; i <= stickerCnt; i++)
        {
            scanf("%d", &stickers[i][1]);
            maxScores[i][0] = maxScores[i][1] = maxScores[i][2] = 0;
        }

        maxScores[1][1] = stickers[1][0];
        maxScores[1][2] = stickers[1][1];

        for (int i = 2; i <= stickerCnt; i++)
        {
            maxScores[i][0] = MAX(maxScores[i - 1][1], maxScores[i - 1][2]);
            maxScores[i][1] = MAX(maxScores[i - 1][0], maxScores[i - 1][2]) + stickers[i][0];
            maxScores[i][2] = MAX(maxScores[i - 1][0], maxScores[i - 1][1]) + stickers[i][1];
        }

        printf("%d \n", MAX(maxScores[stickerCnt][0], MAX(maxScores[stickerCnt][1], maxScores[stickerCnt][2])));
    }
}