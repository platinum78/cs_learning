#include <cstdio>
#include <queue>

struct GermState
{
    unsigned int num;
    int day;
};

int minDays(unsigned int s, unsigned int t, unsigned int a, unsigned int b)
{
    unsigned int germCnt;
    GermState germState;
    std::queue<GermState> germStates;

    if (b == 1)
    {
        if ((t - s) % a == 0)
            return (t - s) / a;
        else
            return -1;
    }

    germState.day = 0; germState.num = t;
    germStates.push(germState);

    while (!germStates.empty())
    {
        germState = germStates.front();
        germStates.pop();
        // printf("%d, %d \n", germState.day, germState.num);

        if (germState.num == s)
            return germState.day;
        
        ++(germState.day);
        
        if (germState.num % b == 0 && germState.num / b >= s)
        {
            germState.num /= b;
            germStates.push(germState);
            germState.num *= b;
        }
        
        germState.num -= a;
        if (germState.num >= s)
            germStates.push(germState);
        germState.num += a;
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
        printf("#%u %d \n", tc, minDays(s, t, a, b));
    }
}