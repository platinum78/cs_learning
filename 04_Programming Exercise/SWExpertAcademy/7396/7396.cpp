#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <queue>

#define UNDEF   -1
#define RIGHT   0
#define DOWN    1
#define VISITED 2

struct Point
{
    int row;
    int col;
};

char *getForemostName(std::vector< std::vector<char> > &char_map, int height, int width)
{
    // Initialize shortest name array.
    std::vector< std::vector<int> > firstPath(height);
    for (int i = 0; i < firstPath.size(); i++)
        firstPath[i].resize(width);

    int maxDist = height + width - 1;
    int row = height - 1;
    int col = width - 1;
    firstPath[row][col] = UNDEF;

    int idxSum;
    char rightChar, downChar;

    idxSum = (--row) + col;
    
    for (row = 0; row < height; row++)
    {
        for (col = 0; col < width; col++)
        {
            printf("%d %d ", row, col);
            // Test downside.
            if (row + 1 < height)
                downChar = char_map[row + 1][col];
            else
                downChar = 'z' + 1;
            
            // Test rightside.
            if (col + 1 < width)
                rightChar = char_map[row][col + 1];
            else
                rightChar = 'z' + 1;
            
            // Compare right and down, and then determine the direction.
            if (rightChar < downChar)
                firstPath[row][col] = RIGHT;
            else if (downChar < rightChar)
                firstPath[row][col] = DOWN;
            else
                firstPath[row][col] = UNDEF;
        }
    }

    row = col = 0;
    int idx = 0;
    char *newString = new char[maxDist + 1];
    while (firstPath[row][col] != UNDEF)
    {
        newString[idx++] = char_map[row][col];
        if (firstPath[row][col] == RIGHT)
            ++col;
        else
            ++row;
    }
    newString[idx] = '\0';

    return newString;
}

int main(void)
{
    freopen("input.txt", "r", stdin);

    std::vector< std::vector<char> > charMap(2000);
    for (int i = 0; i < charMap.size(); i++)
        charMap[i].resize(2000);

    int tcCnt;
    int height, width;
    scanf("%d", &tcCnt);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%d %d", &height, &width);
        for (int r = 0; r < height; r++)
            for (int c = 0; c < width; c++)
                scanf("%c", &charMap[r][c]);
        
        printf("#%d %s \n", tc, getForemostName(charMap, height, width));
    }

    return 0;
}