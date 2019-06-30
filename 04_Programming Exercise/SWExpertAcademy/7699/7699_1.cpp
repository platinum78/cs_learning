#include <cstdio>
#include <cctype>
#include <vector>

#define MAX(X, Y)   (X > Y ? X : Y)
int islandMap[21][21];
int islandHeight, islandWidth;
bool visited[26];

bool isPointValid(int height, int width, int row, int col)
{
    if (row < 0 || row >= height)
        return false;
    if (col < 0 || col >= height)
        return false;
    return true;
}

int findBestTour_aux(int row, int col, int place_cnt)
{
    // if (visited[islandMap[row][col]])
    //     return place_cnt - 1;
    
    int maxPlaces = 0;

    // Test east.
    if (isPointValid(islandHeight, islandWidth, row, col + 1) && !visited[islandMap[row][col + 1]])
    {
        visited[islandMap[row][col]] = true;
        maxPlaces = MAX(maxPlaces, findBestTour_aux(row, col + 1, place_cnt + 1));
        visited[islandMap[row][col]] = false;
    }

    // Test north.
    if (isPointValid(islandHeight, islandWidth, row - 1, col) && !visited[islandMap[row - 1][col]])
    {
        visited[islandMap[row][col]] = true;
        maxPlaces = MAX(maxPlaces, findBestTour_aux(row - 1, col, place_cnt + 1));
        visited[islandMap[row][col]] = false;
    }

    // Test west.
    if (isPointValid(islandHeight, islandWidth, row, col - 1) && !visited[islandMap[row][col - 1]])
    {
        visited[islandMap[row][col]] = true;
        maxPlaces = MAX(maxPlaces, findBestTour_aux(row, col - 1, place_cnt + 1));
        visited[islandMap[row][col]] = false;
    }

    // Test south.
    if (isPointValid(islandHeight, islandWidth, row + 1, col) && !visited[islandMap[row + 1][col]])
    {
        visited[islandMap[row][col]] = true;
        maxPlaces = MAX(maxPlaces, findBestTour_aux(row + 1, col, place_cnt + 1));
        visited[islandMap[row][col]] = false;
    }

    return maxPlaces;
}

int findBestTour(std::vector< std::vector<int> > &island_map)
{
    std::vector<bool> placeVisited(26, false);
    return findBestTour_aux(1, 1, 1);
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    int tcCnt;
    char charBuf;
    scanf("%d", &tcCnt);
    
    int islandHeight, islandWidth;
    std::vector< std::vector<int> > islandMap;
    
    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%d %d", &islandHeight, &islandWidth);
        for (int r = 0; r < islandHeight; r++)
        {
            for (int c = 0; c < islandWidth; c++)
            {
                do
                {
                    charBuf = getchar();
                } while (!isalpha(charBuf));
                islandMap[r][c] = int(charBuf) - int('A');
            }
        }

        printf("#%d %d \n", tc, findBestTour(islandMap));
    }
}