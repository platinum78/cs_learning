#include <cstdio>

int main(void)
{
    freopen("input.txt", "r", stdin);

    char str[131];
    int tcCnt;
    scanf("%d", &tcCnt);

    // Filtering booleans.
    int type, state;

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%s", str);
        type = 0;
        state = 0;
        
        for (int i = 0; str[i + 1] != '\0'; i++)
        {
            if (type == 0)
            {
                if (str[i] == 'F' && str[i + 1] == 'F')
                {
                    type = 1;
                    state = 1;
                }
                else if (str[i] == 'F' && str[i + 1] == 'C')
                {
                    type = 2;
                    state = 1;
                }
                else
                {
                    state = -1;
                    break;
                }
            }
            else if (type == 1)
            {
                switch (state)
                {
                case 1:
                    if (str[i + 1] == 'M')
                        state++;
                    else if (str[i + 1] != 'F')
                        state = -1;
                    break;
                case 2:
                    if (str[i + 1] == 'C')
                        state++;
                    else
                        state = -1;
                    break;
                case 3:
                    if (str[i + 1] == 'M')
                        state++;
                    else
                        state = -1;
                    break;
                case 4:
                    if (str[i + 1] == 'F')
                        type = state = 0;
                    else if (str[i + 1] != 'M')
                        state = -1;
                    break;
                }

                if (state == -1)
                    break;
            }
            else if (type == 2)
            {
                switch (state)
                {
                case 1:
                    if (str[i + 1] == 'M')
                        state++;
                    else if (str[i + 1] != 'C')
                        state = -1;
                    break;
                case 2:
                    if (str[i + 1] == 'F')
                        state++;
                    else
                        state = -1;
                    break;
                case 3:
                    if (str[i + 1] == 'F')
                        type = state = 0;
                    else
                        state = -1;
                }
                if (state == -1)
                    break;
            }
        }
            
        if ((type == 1 && state == 4) || (type == 2 && state == 3))
            printf("#%d %s: DETECTED! \n", tc, str);
        else
            printf("#%d %s: NOTHING! \n", tc, str);
    }
}