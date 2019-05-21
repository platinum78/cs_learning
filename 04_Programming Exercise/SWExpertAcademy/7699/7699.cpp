#include <cstdio>
#include <cctype>
#include <vector>

#define MAX(X, Y)   (X > Y ? X : Y)

struct Point
{
    int row;
    int col;
};

bool isPointValid(int height, int width, Point &point)
{
    if (point.row < 0 || point.row >= height)
        return false;
    if (point.col < 0 || point.col >= height)
        return false;
    return true;
}

int findBestTour_aux(std::vector< std::vector<int> > &island_map, std::vector<bool> &place_visited,
                     Point &place, int place_cnt)
{
    if (place_visited[island_map[place.row][place.col]])
        return place_cnt - 1;
    
    int height = island_map.size();
    int width = island_map[0].size();
    int maxPlaces = 0;
    Point next;

    // Test east.
    next = { place.row, place.col + 1 };
    if (isPointValid(height, width, next))
    {
        place_visited[island_map[place.row][place.col]] = true;
        maxPlaces = MAX(maxPlaces, findBestTour_aux(island_map, place_visited, next, place_cnt + 1));
        place_visited[island_map[place.row][place.col]] = false;
    }

    // Test north.
    next = { place.row - 1, place.col };
    if (isPointValid(height, width, next))
    {
        place_visited[island_map[place.row][place.col]] = true;
        maxPlaces = MAX(maxPlaces, findBestTour_aux(island_map, place_visited, next, place_cnt + 1));
        place_visited[island_map[place.row][place.col]] = false;
    }

    // Test west.
    next = { place.row, place.col - 1 };
    if (isPointValid(height, width, next))
    {
        place_visited[island_map[place.row][place.col]] = true;
        maxPlaces = MAX(maxPlaces, findBestTour_aux(island_map, place_visited, next, place_cnt + 1));
        place_visited[island_map[place.row][place.col]] = false;
    }

    // Test south.
    next = { place.row + 1, place.col };
    if (isPointValid(height, width, next))
    {
        place_visited[island_map[place.row][place.col]] = true;
        maxPlaces = MAX(maxPlaces, findBestTour_aux(island_map, place_visited, next, place_cnt + 1));
        place_visited[island_map[place.row][place.col]] = false;
    }

    return maxPlaces;
}

int findBestTour(std::vector< std::vector<int> > &island_map)
{
    std::vector<bool> placeVisited(26, false);
    Point init = {0, 0};
    return findBestTour_aux(island_map, placeVisited, init, 1);
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    int tcCnt;
    char charBuf;
    scanf("%d", &tcCnt);
    
    int height, width;
    std::vector< std::vector<int> > islandMap;
    Point init;
    
    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%d %d", &height, &width);
        islandMap.resize(height);
        for (int r = 0; r < islandMap.size(); r++)
        {
            islandMap[r].resize(width);
            for (int c = 0; c < islandMap[r].size(); c++)
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