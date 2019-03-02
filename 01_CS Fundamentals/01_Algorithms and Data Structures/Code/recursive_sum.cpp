#include <iostream>
#include <vector>

int recursiveSum(std::vector<int>& arr, int idx)
{
    if (idx == 1)
        return arr[idx - 1];
    return arr[idx - 1] + recursiveSum(arr, idx - 1);
}

int main(void)
{
    std::vector<int> arr(1, 100);
    std::cout << recursiveSum(arr, arr.size()) << std::endl;
}