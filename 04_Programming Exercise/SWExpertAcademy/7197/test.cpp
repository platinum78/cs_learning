#include <cstdio>

typedef struct Test_
{
    int x;
    int y;
} Test;

void printTest(Test test)
{
    printf("x: %d, y: %d \n", test.x, test.y);
}

int main(void)
{
    printTest((Test){ 1, 2 });
}