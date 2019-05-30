#include <cstdio>
#include <cctype>
#include <vector>

int main(void)
{
    freopen("input.txt", "r", stdin);

    int tcCnt, diversity;
    char charBuf;
    scanf("%d", &tcCnt);
    std::vector<bool> included(10);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        for (int i = 0; i < 10; i++)
            included[i] = false;
        
        // Move until number.
        do
        {
            charBuf = getchar();
        } while (!isdigit(charBuf));

        do
        {
            included[charBuf - '0'] = true;
            charBuf = getchar();
        } while (isdigit(charBuf));

        diversity = 0;
        for (int i = 0; i < 10; i++)
            if (included[i])
                ++diversity;
        
        printf("#%d %d \n", tc, diversity);
    }

    return 0;
}