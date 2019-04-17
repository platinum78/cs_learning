#include <cstdio>
#include <iostream>
#include <vector>

void insertionSort(std::vector<int> &arr)
{
    std::vector<int> arrSorted;
    arrSorted.resize(arr.size());
    arrSorted[0] = arr[0];
    int buf;
    
    for (int i = 1; i < arr.size(); i++)
    {
        arrSorted[i] = arr[i];
        for (int j = i - 1; j >= 0 && arrSorted[j] > arrSorted[j + 1]; j--)
        {
            buf = arrSorted[j];
            arrSorted[j] = arrSorted[j + 1];
            arrSorted[j + 1] = buf;
        }
    }

    for (int i = 0; i < arr.size(); i++)
        arr[i] = arrSorted[i];
}

int main(void)
{
    std::vector<int> arr = { 3, 2, 1, 5, 4 };
    insertionSort(arr);
    for (int i = 0; i < arr.size(); i++)
        fprintf(stdout, "%d ", arr[i]);
    fprintf(stdout, "\n");
    return 0;
}