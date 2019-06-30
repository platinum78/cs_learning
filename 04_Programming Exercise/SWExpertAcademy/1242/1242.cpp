// SWExpertAcademy Problem #1242
// Begin: 19 FEB 2019, 17:41

#include <cstdio>
#include <cctype>
#include <memory.h>

char rawCode[8000];
int code[8];
int digitLengths[4];
char lengthRatio[10][4] = {
    { 3, 2, 1, 1 }, // 0
    { 2, 2, 2, 1 }, // 1
    { 2, 1, 2, 2 }, // 2
    { 1, 4, 1, 1 }, // 3
    { 1, 1, 3, 2 }, // 4
    { 1, 2, 3, 1 }, // 5
    { 1, 1, 1, 4 }, // 6
    { 1, 3, 1, 2 }, // 7
    { 1, 2, 1, 3 }, // 8
    { 3, 1, 1, 2 }, // 9
};

bool verifyCode()
{
    int oddSum = code[0] + code[2] + code[4] + code[6];
    int evenSum = code[1] + code[3] + code[5];

    if ((oddSum * 3 + evenSum + code[7]) % 10 == 0)
        return true;
    else
        return false;
}

int findDigitWidth(int endpoint)
{
    int codeLen = 0;
    int idx = endpoint;
    while (rawCode[idx] == '1')
    {
        ++codeLen;
        --idx;
    }
    while (rawCode[idx] == '0')
    {
        ++codeLen;
        --idx;
    }
    while (rawCode[idx] == '1')
    {
        ++codeLen;
        --idx;
    }
    while (rawCode[idx] == '0')
    {
        ++codeLen;
        --idx;
    }

    return codeLen;
}

int convertDigit(int endpoint, int len_factor)
{
    int digitLen = 0, totalLen = 7 * len_factor;
    int idx = endpoint, lenIdx = 0;
    char thisNum = '1', prevNum = '1';

    for (int i = 0; i < totalLen; i++)
    {
        if (thisNum != prevNum)
        {
            digitLengths[lenIdx++] = digitLen;
            digitLen = 0;
        }
        ++digitLen;
    }

    for (int i = 0; i < 4; i++)
        digitLengths[i] /= len_factor;
    
    bool isDifferent = false;
    for (int i = 0; i < 10; i++)
    {
        isDifferent = false;
        for (int j = 0; j < 4; j++)
        {
            if (digitLengths[j] != lengthRatio[i][j])
            {
                isDifferent = true;
                break;
            }
        }

        if (!isDifferent)
            return i;
    }
}

int convertCode(int endpoint)
{
    bool isCodeFound = false;
    
    int idx = endpoint;
    int codeWidth = findDigitWidth(idx);
    int digit;
    
    for (int i = 0; i < 8; i++)
    {
        digit = convertDigit(endpoint, codeWidth / 7);
        code[7 - i] = digit;
        endpoint -= codeWidth;
    }

    return endpoint - codeWidth;
}

int main(void)
{
    int tcCnt;
    int width, height;
    scanf("%d", &tcCnt);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        char charBuf;
        bool isDifferent = false;
        scanf("%d %d", &height, &width);

        // Read the map of codes.
        for (int h = 0; h < height; h++)
        {
            for (int w = 0; w < width; w++)
            {
                do
                {
                    charBuf = getchar();
                } while (!isalnum(charBuf));
                rawCode
            }
        }

        
    }
}