#include <iostream>

int main(void)
{
    int num, tcNum, numMaxExpanded = 1, tcCnt;
    int callCnt[41][2];
    for (int i = 0; i < 41; i++)
        for (int j = 0; j < 2; j++)
            callCnt[i][j] = 0;
    
    callCnt[0][0] = 1;
    callCnt[1][1] = 1;

    std::cin >> tcCnt;
    
    for (int tc = 1; tc <= tcCnt; tc++)
    {
        std::cin >> tcNum;

        if (tcNum == 0 || tcNum == 1)
        {
            printf("%d %d \n", callCnt[tcNum][0], callCnt[tcNum][1]);
        }
        else
        {
            for (num = numMaxExpanded + 1; num <= tcNum; num++)
            {
                callCnt[num][0] = callCnt[num - 1][0] + callCnt[num - 2][0];
                callCnt[num][1] = callCnt[num - 1][1] + callCnt[num - 2][1];
            }
            numMaxExpanded = num - 1;
            printf("%d %d \n", callCnt[tcNum][0], callCnt[tcNum][1]);
        }
    }

    return 0;
}