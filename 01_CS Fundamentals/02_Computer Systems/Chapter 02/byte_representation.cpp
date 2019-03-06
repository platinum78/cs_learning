#include <cstdio>
#include <iostream>
#include <vector>

typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    int i;
    for (i = 0; i < len; i++)
        printf("%.2x ", start[i]);
    printf("\n");
}

void show_int(int x)
{
    show_bytes(byte_pointer(&x), sizeof(int));
}

void show_float(int x)
{
    show_bytes(byte_pointer(&x), sizeof(float));
}

void show_pointer(void *x)
{
    show_bytes(byte_pointer(&x), sizeof(void*));
}

void test_show_bytes(int val)
{
    int ival = val;
    float fval = float(ival);
    int* pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

void inplace_swap(int* x, int* y)
{
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

void reverse_array(std::vector<int>& arr)
{
    int i = 0;
    int j = arr.size() - 1;
    while (i < j)
        inplace_swap(&arr[i++], &arr[j--]);
}