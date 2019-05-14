#include <cstdio>
#include <queue>

struct GermState
{
    unsigned int num;
    int day;
};

int minDays(unsigned int germ_cnt, unsigned int a, unsigned int b, unsigned int t)
{
    unsigned int germCnt;
    GermState germState;
    std::queue<GermState> germStates;

    germState.day = 0; germState.num = germ_cnt;
    germStates.push(germState);

    while (!germStates.empty())
    {
        germState = germStates.front();
        printf("%d, %d \n", germState.day, germState.num);
        germStates.pop();

        if (germState.num == t)
            return germState.day;

        if (a != 0)
        {
            germState.num += a;
            if (germState.num <= t)
            {
                ++(germState.day);
                germStates.push(germState);
                --(germState.day);
            }
            germState.num -= a;
        }

        if (b != 1)
        {
            germState.num *= b;
            if (germState.num <= t)
            {
                ++(germState.day);
                germStates.push(germState);
                --(germState.day);
            }
            germState.num /= b;
        }
    }

    return -1;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    unsigned int tcCnt;
    unsigned int s, t, a, b;
    scanf("%d", &tcCnt);

    for (unsigned int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%u %u %u %u", &s, &t, &a, &b);
        printf("#%u %d \n", tc, minDays(s, a, b, t));
    }
}