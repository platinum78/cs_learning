// SWExpertAcademy Problem #6190
// Start: 16 FEB 2019, 16:40
// Finish: 16 FEB 2019, 16:58

#include <iostream>
#include <vector>

bool isIncreasing(int num_)
{
    int num = num_;
    int rNew = 9, rOld = 9;

    while (num)
    {
        rNew = num % 10;
        if (rNew > rOld)
            return false;
        num /= 10;
        rOld = rNew;
    }
    return true;
}

int findMaxIncreasing(std::vector<int> &numbers)
{
    int product = 0;
    int maxProduct = -1;
    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
        {
            product = numbers[i] * numbers[j];
            if (isIncreasing(product))
                if (product > maxProduct)
                    maxProduct = product;
        }
    }
    return maxProduct;
}

int main(void)
{
    int tcCnt, numCnt;
    std::vector<int> numbers;
    std::cin >> tcCnt;

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        std::cin >> numCnt;
        numbers.resize(numCnt);
        for (int i = 0; i < numCnt; i++)
            std::cin >> numbers[i];
        
        std::cout << "#" << tc << " " << findMaxIncreasing(numbers) << std::endl;
    }

    return 0;
}