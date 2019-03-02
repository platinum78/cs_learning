#include <iostream>
#include <vector>
#include <cstdio>
#include <ctype.h>

int cowTypeCulmulative[3][100000];

void printCowType(int leftBound, int rightBound)
{
    int type1Cow, type2Cow, type3Cow;
    if (leftBound == 1)
    {
        type1Cow = cowTypeCulmulative[0][rightBound - 1];
        type2Cow = cowTypeCulmulative[1][rightBound - 1];
        type3Cow = cowTypeCulmulative[2][rightBound - 1];
    }
    else
    {
        type1Cow = cowTypeCulmulative[0][rightBound - 1] - cowTypeCulmulative[0][leftBound - 2];
        type2Cow = cowTypeCulmulative[1][rightBound - 1] - cowTypeCulmulative[1][leftBound - 2];
        type3Cow = cowTypeCulmulative[2][rightBound - 1] - cowTypeCulmulative[2][leftBound - 2];
    }
    std::cout << type1Cow << " " << type2Cow << " " << type3Cow << std::endl;
    return;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    int tcCnt, cowCnt, questionCnt;
    char cowType;
    int leftBound, rightBound;
    int type1Cow, type2Cow, type3Cow;
    std::cin >> tcCnt;

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        std::cin >> cowCnt >> questionCnt;

        type1Cow = type2Cow = type3Cow = 0;

        for (int c = 0; c < cowCnt; c++)
        {
            cowType = getchar();
            while (!isdigit(cowType))
                cowType = getchar();
            switch (cowType)
            {
            case '1':
                ++type1Cow;
                break;
            case '2':
                ++type2Cow;
                break;
            case '3':
                ++type3Cow;
                break;
            }
            cowTypeCulmulative[0][c] = type1Cow;
            cowTypeCulmulative[1][c] = type2Cow;
            cowTypeCulmulative[2][c] = type3Cow;
        }

        std::cout << "#" << tc << std::endl;
        for (int q = 0; q < questionCnt; q++)
        {
            std::cin >> leftBound >> rightBound;
            printCowType(leftBound, rightBound);
        }
    }

    return 0;
}

