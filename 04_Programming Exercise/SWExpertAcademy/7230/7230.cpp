#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

int findMultipleOf11_(std::vector<std::string>&, std::vector<int>&, std::vector<int>&, int, int);

int findMultipleOf11(std::vector<std::string>& numbers, int denominator)
{
    std::vector<int> indices(numbers.size());
    std::vector<int> indexOrder(numbers.size());
    for (int i = 0; i < indices.size(); i++)
        indices[i] = i;
    
    return findMultipleOf11_(numbers, indices, indexOrder, denominator, numbers.size());
}

int findMultipleOf11_(std::vector<std::string>& numbers, std::vector<int>& indices,
                    std::vector<int>& indexOrder, int denominator, int depth)
{
    if (depth == 0)
    {
        int digitSum = 0;
        int sign = 1;

        for (int i = 0; i < numbers.size(); i++)
        {
            // std::cout << indexOrder[i];
            for (int j = 0; j < numbers[indexOrder[i]].length(); j++)
            {
                digitSum = ((digitSum % denominator) * (10 % denominator) + int(numbers[i][j] - '0')) % denominator;
            }
        }
        // std::cout << std::endl;

        if (digitSum % denominator == 0)
            return 1;
        else
            return 0;
    }

    int multipleCnt = 0;
    for (int i = 0; i < indices.size(); i++)
    {
        if (indices[i] < 0)
            continue;
        indexOrder[numbers.size() - depth] = indices[i];
        indices[i] = -1;
        multipleCnt += findMultipleOf11_(numbers, indices, indexOrder, denominator, depth - 1);
        indices[i] = indexOrder[numbers.size() - depth];
    }
    return multipleCnt;
}

int main(void)
{
    freopen("input.txt", "r", stdin);

    int tcCnt = 0;
    int numCnt, denominator;
    std::vector<std::string> numbers;
    std::cin >> tcCnt;

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        std::cin >> numCnt;
        numbers.resize(numCnt);
        // std::cout << numbers.size() << std::endl;

        for (int n = 0; n < numCnt; n++)
            std::cin >> numbers[n];
        std::cin >> denominator;
        std::cout << "#" << tc << " " << "Numbers: " << numCnt << ", denominator: " << denominator;
        std:: cout << " : " << findMultipleOf11(numbers, denominator) << std::endl;
    }
}