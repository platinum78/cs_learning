#include <cstdio>
#include <cstring>
#define DIV 1000000007
char strBuf[1001];

long tripleCmp(long n1, long n2, long n3)
{
    if (n1 == n2)
    {
        if (n2 == n3)
            return 1;
        else
            return 2;
    }
    else
    {
        if (n2 == n3)
            return 2;
        else if (n1 == n3)
            return 2;
        else
            return 3;
    }
}

long charReplacable(int len)
{
    long totalCase = 1;

    if (strBuf[0] != strBuf[1])
        totalCase *= 2;
    // else
    //     ++totalCase;
    
    for (int i = 1; i < len - 1; i++)
        totalCase = totalCase * tripleCmp(strBuf[i - 1], strBuf[i], strBuf[i + 1]) % DIV;
    
    if (strBuf[len - 2] != strBuf[len - 1])
        totalCase *= 2;
    // else
    //     ++totalCase;

    return totalCase % DIV;
}

int main(void)
{
    freopen("input.txt", "r", stdin);

    int tcCnt;
    scanf("%d", &tcCnt);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%s", strBuf);
        printf("#%d %ld \n", tc, charReplacable(strlen(strBuf)));
    }

    return 0;
}

