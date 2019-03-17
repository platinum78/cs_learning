#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

class findMultipleOf
{
    public:
    findMultipleOf();
    int findMultipleCase();
    int findMultipleCase_(int depth);

    private:
    std::vector<std::string> numbers;
    std::vector<int> index;
    std::vector<int> indexOrder;
    int denominator, numCnt, totalDigits;
};

findMultipleOf::findMultipleOf()
{
    std::cin >> numCnt;
    numbers.resize(numCnt);
    totalDigits = 0;
    for (int i = 0; i < numCnt; i++)
    {
        std::cin >> numbers[i];
        totalDigits += numbers[i].length();
    }
        
    index.resize(numCnt);
    for (int i = 0; i < numCnt; i++)
        index[i] = i;
    indexOrder.resize(numCnt);
}

int findMultipleOf::findMultipleCase()
{
    return findMultipleCase_(numCnt);
}

int findMultipleOf::findMultipleCase_(int depth)
{
    if (depth == 0)
    {
        int iterCnt = 0;
        int remainder = 0, totalRemainder = 0;
        for (int i = 0; i < numCnt; i++)
        {
            for (int j = 0; j < numbers[i].length(); j++)
            {
                remainder = int(numbers[i][j] - '0') % denominator;
                for (int k = 0; k < totalDigits - iterCnt - 1; k++)
                    remainder = (remainder * (10 % denominator)) % denominator;
                totalRemainder += remainder;
            }
        }

        if (totalRemainder % denominator == 0)
            return 1;
        else
            return 0;
    }

    int caseCnt = 0;
    int idxBuf;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (index[i] < 0)
            continue;
        
        indexOrder[numCnt - depth] = index[i];
        index[i] = -1;
        caseCnt += findMultipleCase_(depth - 1);
        index[i] = indexOrder[numCnt - depth];
    }
    return caseCnt;
}

int main(void)
{
    freopen("input.txt", "r", stdin);

    int tcCnt;
    std::cin >> tcCnt;

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        findMultipleOf multiple;
        std::cout << "#" << tc << " " << multiple.findMultipleCase() << std::endl;
    }

    return 0;
}