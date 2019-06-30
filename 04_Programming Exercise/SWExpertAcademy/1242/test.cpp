#include <cstdio>

int main(void)
{
    int arr[2][2] = { { 1, 2 }, { 3, 4 } };

    printf("%d", **arr);
}