#include <cstdio>
#include <cmath>

int cube(int n)
{
    return n * n * n;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    int s0 = 0, s1 = 1, s, start, iter;
    int N, M, answer;
    int *cache = new int[1000000];
    int tcCnt;
    bool found;
    scanf("%d", &tcCnt);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        s0 = 0; s1 = 1;
        scanf("%d %d", &N, &M);
        cache[0] = 0;
        cache[1] = s1 % M;
        
        if (N == 0)
            answer = cache[0];
        else if (N == 1)
            answer = cache[1];
        else if (M == 1)
            answer = 0;
        else if (N <= 1000000)
        {
            iter = 2;
            while (1)
            {
                s = (cube(s0) % M + cube(s1) % M) % M;
                cache[iter] = s;
                s0 = s1;
                s1 = s;

                if (iter == N)
                {
                    answer = cache[iter];
                    break;
                }
                ++iter;
            }
        }
        else
        {
            iter = 2;
            while (1)
            {
                s = (cube(s0) % M + cube(s1) % M) % M;
                cache[iter] = s;
                s0 = s1;
                s1 = s;
                ++iter;
            }

            for (start = 0; start < iter - 2; start++)
                if (cache[iter - 1] == cache[start] && cache[iter] == cache[start + 1])
                    break;

            N -= start;
            N %= (iter - start);
            answer = cache[start + N];

        }
        printf("#%d %d \n", tc, answer);
    }
}