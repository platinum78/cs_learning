#include <cstdio>
#include <vector>

void newLine(std::vector<char> &old_line, std::vector<char> &new_line)
{
    int frontEnd = 0, rearEnd = old_line.size() - 1;
    char commonToken, frontToken, rearToken;
    int newLineCursor = 0;

    while (frontEnd <= rearEnd)
    {
        printf("frontEnd: %c @ %d | rearEnd: %c @ %d \n", old_line[frontEnd], frontEnd, old_line[rearEnd], rearEnd);
        if (old_line[frontEnd] < old_line[rearEnd])
        {
            new_line[newLineCursor++] = old_line[frontEnd++];
            continue;
        }
        else if (old_line[rearEnd] < old_line[frontEnd])
        {
            new_line[newLineCursor++] = old_line[rearEnd--];
            continue;
        }
        else
        {
            commonToken = old_line[frontEnd];
            for (int i = frontEnd; old_line[i] == commonToken; i++)
                frontToken = old_line[i];
            for (int i = rearEnd; old_line[i] == commonToken; i--)
                rearToken = old_line[i];
            
            if (frontToken < rearToken)
                while (old_line[frontEnd] == commonToken)
                    new_line[newLineCursor++] = old_line[frontEnd++];
            else
                while (old_line[rearEnd] == commonToken)
                    new_line[newLineCursor++] = old_line[rearEnd--];
        }
    }
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    int tcCnt;
    int parrotCnt;
    std::vector<char> parrotOldLine, parrotNewLine;
    scanf("%d", &tcCnt);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        // Get the number of parrots and resize line.
        scanf("%d", &parrotCnt);
        parrotOldLine.resize(parrotCnt);
        parrotNewLine.resize(parrotCnt);

        for (int i = 0; i < parrotCnt; i++)
            scanf("%c", &parrotOldLine[i]);
        
        printf("Old line: ");
        for (int i = 0; i < parrotCnt; i++)
            printf("%c", parrotOldLine[i]);
        printf("\n");

        newLine(parrotOldLine, parrotNewLine);
        printf("#%d ", tc);
        for (int i = 0; i < parrotNewLine.size(); i++)
            printf("%c", parrotNewLine[i]);
        printf("\n");
    }
}