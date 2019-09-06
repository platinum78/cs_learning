#include <cstdio>

int main(void)
{
    freopen("input.txt", "r", stdin);

    int **g = new int*[1001];
    for (int i = 0; i < 1001; i++)
        g[i] = new int[4];
    int tcCnt, edgeCnt;
    int n1, n2, tailLen = 0;
    int thisNode, prevNode;
    scanf("%d", &tcCnt);
    
    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%d", &edgeCnt);
        for (int i = 1; i <= edgeCnt; i++)
            g[i][0] = 0;
        
        for (int i = 1; i <= edgeCnt; i++)
        {
            scanf("%d %d", &n1, &n2);
            g[n1][0]++;
            g[n2][0]++;
            g[n1][g[n1][0]] = n2;
            g[n2][g[n2][0]] = n1;
        }

        for (int i = 1; i <= edgeCnt; i++)
        {
            if (g[i][0] == 1)
            {
                prevNode = 0; thisNode = i;
                while (g[thisNode][0] <= 2)
                {
                    if (g[thisNode][1] != prevNode)
                    {
                        prevNode = thisNode;
                        thisNode = g[thisNode][1];
                    }
                    else
                    {
                        prevNode = thisNode;
                        thisNode = g[thisNode][2];
                    }
                    tailLen++;
                }
            }
        }

        printf("#%d %d \n", tc, edgeCnt - tailLen);
    }
}