#include <cstdio>
#include <cstring>

char *N, *num;
int x, y, len;

bool dfs(int idx)
{
    if (idx == len - 1)
    {
        if (N[idx] - '0' >= y)
        {
            num[idx] = '0' + y;
            return true;
        }
        else if (N[idx] - '0' >= x)
        {
            num[idx] = '0' + x;
            return true;
        }
        else
            return false;
    }
    
    if (N[idx] - '0' >= y)
        num[idx] = '0' + y;
    else if (N[idx])
}

bool makeNum(char *N, char *num, int x, int y)
{
    int len = strlen(num);
    int i, j;
    bool cond;

    if (len == 1)
        if (int(N[0] - '0') < y)
            if (int(N[0] - '0') < x || x == 0)
                return false;

    if (x == 0)
    {
        cond = true;
        for (i = 0; i < len; i++)
        {
            num[i] = '0' + y;
            if (N[i] < y)
            {
                for (j = 0; j < len - 1; j++)
                    num[j] = '0' + y;
                num[len - 1] = '\0';
                cond = false;
                break;
            }
        }
        if (cond)
            num[len] = '\0';

        return true;
    }

    if (N[0] > y)
    {
        for (i = 0; i < len; i++)
            num[i] = '0' + y;
        num[len] = '\0';
    }
    else if (N[0] == y)
    {
        i = 0;
        while (i < len)
        {
            if (N[i] >= y)
                num[i] = '0' + y;
            else if (N[i] > x)
            {
                num[i] = '0' + x;
                for (j = i + 1; j < len; j++)
                    num[i] = '0' + y;
                break;
            }
            else if (N)
                break;
        }

        
    }
    else if (N[0] > x)
    {
        num[0] = '0' + x;
        for (i = 1; i < len; i++)
            num[i] = '0' + y;
        return true;
    }
    else if (N[0] == x)
    {
        cond = true;
        for (i = 0; i < len; i++)
        {
            num[i] = '0' + x;

            if (N[i] < x)
            {
                for (j = 0; j < len - 1; j++)
                    num[j] = '0' + y;
                num[len - 1] = '\0';
                cond = false;
                break;
            }
        }
        if (cond)
            num[len] = '\0';
        return true;
    }
    else
        return false;
}

int main(void)
{
    char *N = new char[100001];
    char *num = new char[100001];
    int x, y, len, pos, i, j;
    int tcCnt;
    scanf("%d", &tcCnt);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%s %d %d", N, x, y);
        len = strlen(N);
    }
}