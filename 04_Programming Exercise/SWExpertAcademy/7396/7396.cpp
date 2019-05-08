#include <cstdio>
#include <ctype.h>
#include <vector>

std::vector<char> nameMaker(std::vector< std::vector<char> > &char_map)
{
    int rightMove = char_map[0].size();
    int downMove = char_map.size();
    std::vector<char> name(rightMove + downMove + 1);
    int cursor = 0, row = 0, col = 0;
    char right, down;

    name[cursor] = char_map[row][col];
    while (rightMove != 0 or downMove != 0)
    {
        printf("%d, %d, %d, %d \n", row, col, rightMove, downMove);
        if (col < char_map[0].size())
            right = char_map[row][col + 1];
        if (row < char_map.size())
            down = char_map[row + 1][col];

        if (down < right)
        {
            name[cursor++] = char_map[row++][col];
            --downMove;
        }
        else if (right < down)
        {
            name[cursor++] = char_map[row][col++];
            --rightMove;
        }
        
        if (row == char_map.size() - 1)
            down = 'z' + 1;
        if (col == char_map[0].size() - 1)
            right = 'z' + 1;
    }

    return name;
}

int main(void)
{
    freopen("input.txt", "r", stdin);

    int tcCnt;
    int mapWidth, mapHeight;
    char charBuf;
    std::vector<char> foremostName, currentName;
    std::vector< std::vector<char> > charMap;
    scanf("%d", &tcCnt);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%d %d", &mapHeight, &mapWidth);
        charMap.resize(mapHeight);
        for (int r = 0; r < charMap.size(); r++)
            charMap[r].resize(mapWidth);

        for (int r = 0; r < mapHeight; r++)
        {
            for (int c = 0; c < mapWidth; c++)
            {
                do
                {
                    charBuf = getchar();
                } while (!islower(charBuf));
                charMap[r][c] = charBuf;
            }
        }

        std::vector<char> name = nameMaker(charMap);

        printf("#%d ", tc);
        for (int i = 0; i < foremostName.size(); i++)
            printf("%c", foremostName[i]);
        printf("\n");
    }
}