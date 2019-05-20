#include <vector>

int matrixChainRecursive(std::vector<int> &dimensions, int left_, int right_)
{
    if (left_ == right_)
        return 0;

    if (left_ + 1 == right_)
        return dimensions[left_ - 1] * dimensions[left_] * dimensions[right_];
    
    int minCalc = 0x7FFFFFFF;
    int calc;
    for (int i = left_; i < right_; i++)
    {
        calc = matrixChainRecursive(dimensions, left_, i)
                + matrixChainRecursive(dimensions, i + 1, right_)
                + dimensions[left_ - 1] * dimensions[i] * dimensions[right_];
        if (calc < minCalc)
            minCalc = calc;
    }

    return minCalc;
}