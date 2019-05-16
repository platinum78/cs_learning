#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>

bool precedes(char *str1, char *str2)
{
    if (strcmp(str1, str2) <= 0)
        return true;
    else
        return false;
}

int main(void)
{
    freopen("input.txt", "r", stdin);

    int tcCnt;
    int nameCnt;
    char nameBuf[51];
    char *printedName = nameBuf;
    scanf("%d", &tcCnt);
    std::vector<char*> names;

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%d", &nameCnt);
        names.resize(nameCnt);

        for (int i = 0; i < nameCnt; i++)
        {
            scanf("%s", nameBuf);
            names[i] = new char[strlen(nameBuf) + 1];
            strcpy(names[i], nameBuf);
        }

        std::sort(names.begin(), names.end(), precedes);

        printf("#%d \n", tc);
        
        for (int i = 0; i < names.size(); i++)
        {
            if (strcmp(names[i], printedName))
            {
                printf("%s \n", names[i]);
                printedName = names[i];
                delete names[i];
            }
        }
    }

    return 0;
}