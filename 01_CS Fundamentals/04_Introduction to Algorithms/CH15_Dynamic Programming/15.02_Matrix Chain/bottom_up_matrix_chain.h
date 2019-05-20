#include <vector>

int matrixChainBottomUp(std::vector<int> &dimensions)
{
    int size = dimensions.size() - 1;
    std::vector< std::vector<int> > calcTable;
    calcTable.resize(size);
    for (int i = 0; i < calcTable.size(); i++)
    {
        calcTable[i].resize(size);
        for (int j = 0; j < calcTable[i].size(); j++)
            calcTable[i][j] = 0;
    }
    
    int left, right, length;    // left and right are 1-index (due to dimensions array).
    int calc, minCalc;
    for (length = 1; length <= size; length++)
    {
        for (left = 1; left <= size - length + 1; left++)
        {
            right = left + length - 1;

            if (left == right)
            {
                calcTable[left - 1][right - 1] = 0;
                break;
            }
            
            minCalc = 0x7FFFFFFF;
            for (int split = left; split < right; split++)
            {
                calc = calcTable[left - 1][split - 1] + calcTable[split][right - 1]
                        + dimensions[left - 1] * dimensions[split] * dimensions[right];
                if (calc < minCalc)
                    minCalc = calc;
            }

            calcTable[left - 1][right - 1] = minCalc;
        }
    }

    return calcTable[0][size - 1];
}