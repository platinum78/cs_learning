// Linear search algorithm

#include <iostream>
#include <cstdio>
#include <vector>

template <typename T>
int seek(std::vector<T> &arr, T obj)
{
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] == obj)
            return i;
    return -1;
}

int main(void)
{
    std::vector<int> arr = { 1, 2, 4, 3, 5, 7, 8, 39 };
    fprintf(stdout, "Index: %d \n", seek<int>(arr, 39));
}