#include <cstdio>
#include <cctype>

char map[20][20];
int R, C, typeCnt, maxCnt;
bool exists[26] = { false, };
bool visited[26] = { false, };
const int delta[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

bool isInMap(int r, int c)
{
    if (r >= 0 && r < R && c >= 0 && c < C)
        return true;
    return false;
}

void findMax(int r, int c, int cnt)
{
    maxCnt = (maxCnt > cnt ? maxCnt : cnt);
    if (maxCnt == typeCnt)
        return;
    for (int i = 0; i < 4; i++)
    {
        int r_ = r + delta[i][0];
        int c_ = c + delta[i][1];
        int idx = map[r_][c_] - 'A';

        if (isInMap(r_, c_) &&        // Index in map
            !visited[idx])    // Not visited specific place
        {
            visited[idx] = true;
            findMax(r_, c_, cnt + 1);
            visited[idx] = false;
        }
    }
}

void init()
{
    for (int i = 0; i < 26; i++)
        exists[i] = visited[i] = false;
    typeCnt = maxCnt = 0;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    int tcCnt;
    char charBuf;
    scanf("%d", &tcCnt);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        init();
        scanf("%d %d", &R, &C);

        for (int r = 0; r < R; r++)
        {
            do
            {
                charBuf = getchar();
            } while (!isupper(charBuf));
            for (int c = 0; c < C; c++)
            {
                map[r][c] = charBuf;
                exists[charBuf - 'A'] = true;
                charBuf = getchar();
            }
        }

        for (int i = 0; i < 26; i++)
            if (exists[i])
                ++typeCnt;
        visited[map[0][0] - 'A'] = true;
        findMax(0, 0, 1);
        printf("#%d %d \n", tc, maxCnt);
    }
}