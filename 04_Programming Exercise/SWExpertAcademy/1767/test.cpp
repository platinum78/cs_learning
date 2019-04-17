#include <iostream>
#include <vector>

void printList(std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << "  ";
    std::cout << std::endl;
}

void permutation(std::vector<int> &arr, int depth)
{
    if (depth == 1)
    {
        printList(arr);
        return;
    }
    
    int buf;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
            continue;
        buf = arr[i];
        arr[i] = 0;
        permutation(arr, depth - 1);
        arr[i] = buf;
    }

    return;
}

int main(void)
{
    std::vector<int> arr = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    printList(arr);
    permutation(arr, arr.size());
    return 0;
}