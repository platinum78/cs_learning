#include <cstdio>

int main(void)
{
    int tcCnt;
    long year, month, monthDiff;
    scanf("%ld", &tcCnt);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%ld %ld", &year, &month);
        monthDiff = (year - 2016) * 12 + (month - 1);
        year = 2016 + monthDiff / 13;
        month = 1 + monthDiff % 13;

        printf("#%d %ld %ld \n", tc, year, month);
    }
}