#include <cstdio>
#include <cstring>
#include <memory.h>

int main(void)
{
    freopen("input.txt", "r", stdin);

    char openKey1[1000][11];
    char openKey2[1000][11];
    char cryptoText[1000][11];
    int keyMapping[1000];
    int keyInvMapping[1000];

    int tcCnt, wordCnt;
    scanf("%d", &tcCnt);
    for (int tc = 1; tc <= tcCnt; tc++)
    {
        for (int i = 0; i < 1000; i++)
            keyMapping[i] = -1;

        scanf("%d", &wordCnt);
        for (int i = 0; i < wordCnt; i++)
            scanf("%s", openKey1[i]);
        for (int i = 0; i < wordCnt; i++)
            scanf("%s", openKey2[i]);
        for (int i = 0; i < wordCnt; i++)
            scanf("%s", cryptoText[i]);
        
        for (int i = 0; i < wordCnt; i++)
            for (int j = 0; j < wordCnt; j++)
                if (keyMapping[j] == -1 && strcmp(openKey1[i], openKey2[j]) == 0)
                    keyMapping[j] = i;
        
        for (int i = 0; i < wordCnt; i++)
            keyInvMapping[keyMapping[i]] = i;
        
        printf("%s", cryptoText[keyInvMapping[0]]);
        for (int i = 1; i < wordCnt; i++)
            printf(" %s", cryptoText[keyInvMapping[i]]);
        printf("\n");
    }
}