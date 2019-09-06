#include <cstdio>

int main(void)
{
    freopen("input.txt", "r", stdin);

    int tcCnt;
    int p1x, p1y, p2x, p2y, dx, dy, dxy, jmpCnt;
    scanf("%d", &tcCnt);
    
    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%d %d %d %d", &p1x, &p1y, &p2x, &p2y);
        dx = (p2x > p1x ? p2x - p1x : p1x - p2x);
        dy = (p2y > p1y ? p2y - p1y : p1y - p2y);
        dxy = (dx > dy ? dx - dy : dy - dx);
        jmpCnt = 2 * (dx < dy ? dx : dy) + 4 * (dxy / 2) + dxy % 2;

        printf("#%d %d \n", tc, jmpCnt);
    }
}