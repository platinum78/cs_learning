
#include <cstdio>
#include <vector>
#include <ctype.h>

#define NO_HOLE     0
#define ONE_HOLE    1
#define TWO_HOLES   2

int charType(char chr)
{
    if (chr == 'B')
        return TWO_HOLES;
    else if (chr == 'A' || chr == 'D' || chr == 'O' ||
             chr == 'P' || chr == 'Q' || chr == 'R')
        return ONE_HOLE;
    else
        return NO_HOLE;
}

int main(void)
{
    freopen("input.txt", "r", stdin);

    int tcCnt;
    char charBuf;
    std::vector<int> charTypes(10);
    int str1_len, str2_len, idx;
    bool diff;
    scanf("%d", &tcCnt);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        diff = false;
        // Move until data.
        while (!isupper(charBuf))
            charBuf = getchar();

        str1_len = 0;

        // Read first string.
        do
        {
            charTypes[str1_len++] = charType(charBuf);
            charBuf = getchar();
        } while (isupper(charBuf));

        // Read second string.
        str2_len = 0;
        charBuf = getchar();
        do
        {
            if (charType(charBuf) != charTypes[str2_len] || str1_len == str2_len++)
            {
                diff = true;
                while (isupper(charBuf))
                    charBuf = getchar();
                break;
            }
            charBuf = getchar();
        } while (isupper(charBuf));

        if (!diff)
        {
            if (str1_len == str2_len)
                printf("#%d SAME \n", tc);
            else
                printf("#%d DIFF \n", tc);
        }
        else
            printf("#%d DIFF \n", tc);
        
    }
}