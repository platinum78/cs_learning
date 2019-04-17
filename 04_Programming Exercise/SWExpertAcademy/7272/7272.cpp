#include <iostream>
#include <cstdio>
#include <cstring>

int holeCnt[26] = { 1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 };

bool isSame(char c1, char c2)
{
    if (holeCnt[c1 - 'A'] == holeCnt[c2 - 'A'])
        return true;
    else
        return false;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    char charBuf;
    char strBuf[11];
    int idx = 0;
    int len = 0;

    int tcCnt;
    std::cin >> tcCnt;
    for (int tc = 1; tc <= tcCnt; tc++)
    {
        idx = 0;
        charBuf = getchar();
        while (charBuf != ' ')
        {
            strBuf[idx++] = charBuf;
            charBuf = getchar();
        }
        len = idx;

        fprintf(stdout, "#%d ", tc);
        for (idx = 0; idx < len; idx++)
        {
            charBuf = getchar();
            if (holeCnt[charBuf - 'A'] != holeCnt[strBuf[idx] - 'A'])
            {
                puts("DIFF");
                break;
            }
        }
        if (idx == len)
            puts("SAME");
        
        while (charBuf != '\n')
        {
            charBuf = getchar();
            if (charBuf == EOF)
                break;
        }
    }
}