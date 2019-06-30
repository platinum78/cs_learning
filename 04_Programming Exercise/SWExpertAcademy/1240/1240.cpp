#include <iostream>
#include <cstdio>
#include <cctype>

int codeNum(int code)
{
    switch (code)
    {
    case 0b0001101:
        return 0;
    case 0b0011001:
        return 1;
    case 0b0010011:
        return 2;
    case 0b0111101:
        return 3;
    case 0b0100011:
        return 4;
    case 0b0110001:
        return 5;
    case 0b0101111:
        return 6;
    case 0b0111011:
        return 7;
    case 0b0110111:
        return 8;
    case 0b0001011:
        return 9;
    default:
        return -1;
    }
}

int main(void)
{
    freopen("input.txt", "r", stdin);

    int tcCnt;
    scanf("%d", &tcCnt);

    char secretCode[8];
    char matrix[50][100];
    int matHeight, matWidth;
    int row, col, idx;
    int code;
    bool duplicate;
    int checkSumOdd, checkSumEven;

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%d %d", &matHeight, &matWidth);
        for (int r = 0; r < matHeight; r++)
            for (int c = 0; c < matWidth; c++)
                do
                {
                    matrix[r][c] = getchar();
                } while (!isdigit(matrix[r][c]));

        for (row = 0; row < matHeight; row++)
        {
            for (idx = matWidth - 1; matrix[row][idx] == '0' && idx > 0; idx--);
            if (idx == 0)
                continue;
            idx -= 55;
            
            duplicate = true;
            if (row > 0)
            {
                for (col = idx; col < idx + 56; col++)
                {
                    if (matrix[row][col] != matrix[row - 1][col])
                    {
                        duplicate = false;
                        break;
                    }
                }
                if (duplicate)
                    continue;
            }
            
            for (int i = 0; i < 8; i++)
            {
                code = 0;
                for (int j = 0; j < 7; j++)
                {
                    code <<= 1;
                    if (matrix[row][idx] == '1')
                        ++code;
                    ++idx;
                }
                
                secretCode[i] = codeNum(code);
            }

            checkSumOdd = checkSumEven = 0;
            for (int i = 0; i < 7; i++)
            {
                if (i % 2 == 0)
                    checkSumOdd += secretCode[i];
                else
                    checkSumEven += secretCode[i];
            }

            if ((checkSumOdd * 3 + checkSumEven + secretCode[7]) % 10 != 0)
                printf("#%d %d \n", tc, 0);
            else
                printf("#%d %d \n", tc, checkSumOdd + checkSumEven + secretCode[7]);
        }
    }
}