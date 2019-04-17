#include <iostream>
#include <vector>

template <typename T>
void mergeSort_(std::vector<T> &arr, int leftBound, int rightBound)
{
    if (leftBound == rightBound)
        return;
    if (leftBound + 1 == rightBound)
    {
        if (arr[leftBound] > arr[rightBound])
        {
            arr[leftBound] ^= arr[rightBound];
            arr[rightBound] ^= arr[leftBound];
            arr[leftBound] ^= arr[rightBound];
        }
        return;
    }

    int middleIdx = (leftBound + rightBound) / 2;
    mergeSort_<T>(arr, leftBound, middleIdx);
    mergeSort_<T>(arr, middleIdx + 1, rightBound);
    int i = leftBound, j = middleIdx + 1;
    int *pSortBuf, sortBufIdx = 0;
    while (i < middleIdx || j < rightBound)
    {
        pSortBuf = new int[rightBound - leftBound + 1];
        if (arr[i] < arr[j] && i < middleIdx)
            pSortBuf[sortBufIdx++] = arr[i++];
        else
            pSortBuf[sortBufIdx++] = arr[j++];
    }
    for (int i = leftBound; i <= rightBound; i++)
        arr[i] = pSortBuf[i - leftBound];
}

template <typename T>
void mergeSort(std::vector<T> &arr)
{
    mergeSort_<int>(arr, 0, arr.size() - 1);
}

int main(void)
{
    std::vector<int> arr = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    mergeSort<int>(arr);
    for (int i = 0; i < arr.size(); i++)
        fprintf(stdout, "%d ", arr[i]);
    fprintf(stdout, "\n");
    return 0;
}