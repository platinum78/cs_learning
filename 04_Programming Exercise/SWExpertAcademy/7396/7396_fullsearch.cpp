#include <cstdio>
#include <ctype.h>
#include <vector>

bool lexPrecedes(std::vector<char> &str1, std::vector<char> &str2)
{
    for (int idx = 0; idx < str1.size(); idx++)
    {
        if (str1[idx] < str2[idx])
            return true;
        else if (str2[idx] < str1[idx])
            return false;
    }

    return false;
}

void nameMaker_(std::vector< std::vector<char> > &char_map,
               std::vector<char> &foremost_name, std::vector<char> &current_name,
               int depth, int right_move, int down_move, bool precedes)
{
    if (right_move == 0 && down_move == 0)
    {
        if (lexPrecedes(current_name, foremost_name))
            for (int idx = 0; idx < current_name.size(); idx++)
                foremost_name[idx] = current_name[idx];
        return;
    }

    char cBuf;
    int row = char_map.size() - down_move - 1;
    int col = char_map[0].size() - right_move - 1;
    if (right_move > 0)
    {
        cBuf = char_map[row][col + 1];
        if (!precedes)
        {
            if (cBuf < foremost_name[depth])
                precedes = true;
            else if (cBuf > foremost_name[depth])
                return;
        }
        current_name[depth] = cBuf;
        nameMaker_(char_map, foremost_name, current_name, depth + 1, right_move - 1, down_move, precedes);
    }
    if (down_move > 0)
    {
        cBuf = char_map[row + 1][col];
        current_name[depth] = cBuf;
        nameMaker_(char_map, foremost_name, current_name, depth + 1, right_move, down_move - 1, precedes);
    }

    return;
}

void nameMaker(std::vector< std::vector<char> > &char_map,
               std::vector<char> &foremost_name, std::vector<char> &current_name)
{
    current_name[0] = char_map[0][0];
    int right_move = char_map[0].size() - 1;
    int down_move = char_map.size() - 1;
    nameMaker_(char_map, foremost_name, current_name, 1, right_move, down_move, false);
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

        foremostName.resize(mapHeight + mapWidth - 1);
        currentName.resize(mapHeight + mapWidth - 1);
        for (int i = 0; i < foremostName.size(); i++)
            foremostName[i] = 'z';
        currentName[0] = charMap[0][0];
        nameMaker(charMap, foremostName, currentName);
        
        printf("#%d ", tc);
        for (int i = 0; i < foremostName.size(); i++)
            printf("%c", foremostName[i]);
        printf("\n");
    }
}