#include <cstdio>
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

int N[100];
int K[10001];
int k, n;

int main(void)
{
    int minVal = 0x7FFFFFFF;
    int maxCoin = 0;
    bool found = false;

    K[0] = 0;

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++)
        scanf("%d", N + i);
    
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - N[j] > 0 && K[i - N[j]] > 0)
            {
                minVal = MIN(minVal, K[i - N[j]] + 1);
                found = true;
            }
            else if (i - N[j] == 0)
            {
                minVal = 1;
                found = true;
                break;
            }
        }

        if (found)
            K[i] = minVal;
        else
            K[i] = 0;
        
        minVal = 0x7FFFFFFF;
        found = false;
    }

    if (K[k] > 0)
        printf("%d \n", K[k]);
    else
        printf("-1 \n");
}