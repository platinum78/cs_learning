#include <cstdio>
#include <iostream>

int main(void)
{
    freopen("input.txt", "r", stdin);

    int tcCnt;
    int cowCnt, cowIdx, qCnt, qIdx;
    int leftBound, rightBound;
    int cowType;
    int cowCntByType[3] = { 0, 0, 0 };
    int cowType1Culmulative[100000];
    int cowType2Culmulative[100000];
    int cowType3Culmulative[100000];
    scanf("%d", &tcCnt);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%d %d", &cowCnt, &qCnt);
        cowCntByType[0] = cowCntByType[1] = cowCntByType[2] = 0;

        for (cowIdx = 0; cowIdx < cowCnt; cowIdx++)
        {
            scanf("%d", &cowType);
            ++cowCntByType[cowType - 1];
            cowType1Culmulative[cowIdx] = cowCntByType[0];
            cowType2Culmulative[cowIdx] = cowCntByType[1];
            cowType3Culmulative[cowIdx] = cowCntByType[2];
        }
        
        printf("#%d \n", tc);
        for (qIdx = 0; qIdx < qCnt; qIdx++)
        {
            scanf("%d %d", &leftBound, &rightBound);
            cowCntByType[0] = cowCntByType[1] = cowCntByType[2] = 0;

            if (leftBound == 1)
            {
                cowCntByType[0] = cowType1Culmulative[rightBound - 1];
                cowCntByType[1] = cowType2Culmulative[rightBound - 1];
                cowCntByType[2] = cowType3Culmulative[rightBound - 1];
            }
            else
            {
                cowCntByType[0] = cowType1Culmulative[rightBound - 1] - cowType1Culmulative[leftBound - 2];
                cowCntByType[1] = cowType2Culmulative[rightBound - 1] - cowType2Culmulative[leftBound - 2];
                cowCntByType[2] = cowType3Culmulative[rightBound - 1] - cowType3Culmulative[leftBound - 2];
            }

            printf("%d %d %d \n", cowCntByType[0], cowCntByType[1], cowCntByType[2]);
        }
    }
}