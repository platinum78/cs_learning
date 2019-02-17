#include <vector>
#include <iostream>

// My implementation
void insertionSort(std::vector<int>& arr)
{
    int thisElem;
    int j;

    for (int i = 1; i < arr.size(); i++)
    {
        thisElem = arr[i];
        for (j = i - 1; j >= 0 && thisElem < arr[j]; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = thisElem;
    }
}

// Implementation from the book
void insertionSort_Reference(std::vector<int>& arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        char cur = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > cur)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = cur;
    }
}

int main(void)
{
    std::vector<int> arr({ 3, 7, 5, 6, 9, 2 });
    insertionSort(arr);

    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << "  " << std::endl;
    std::cout << std::endl;

    return 0;
}