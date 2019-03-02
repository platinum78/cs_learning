#include <iostream>
#include <vector>

void iterativeReverse(std::vector<int>& arr)
{
    int i = 0, j = arr.size() - 1;
    int buf;
    while (i < j)
    {
        buf = arr[i];
        arr[i++] = arr[j];
        arr[j--] = buf;
    }
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
    iterativeReverse(arr);
    printArr(arr);
    return 0;
}