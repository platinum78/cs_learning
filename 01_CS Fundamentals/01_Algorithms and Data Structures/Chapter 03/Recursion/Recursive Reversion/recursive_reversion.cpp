#include <iostream>
#include <vector>

void recursiveReverse_(std::vector<int>& arr, int idx)
{
    if (idx == arr.size())
        return;
    int thisElem = arr[idx];
    recursiveReverse_(arr, idx + 1);
    arr[arr.size() - idx - 1] = thisElem;
}

void recursiveReverse(std::vector<int>& arr)
{
    recursiveReverse_(arr, 0);
}

void printArr(std::vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << "  ";
    std::cout << '\n';
}

int main(void)
{
    std::vector<int> arr({ 1, 2, 3, 4, 5, 6, 7 });
    printArr(arr);
    recursiveReverse(arr);
    printArr(arr);
    return 0;
}