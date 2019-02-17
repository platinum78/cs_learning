#include <iostream>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int tapWaterFare(int fareA, int baseB, int thresB, int fareB, int liters)
{
    int aCompany = 0;
    int bCompany = 0;

    aCompany = fareA * liters;
    bCompany = baseB + fareB * max(liters - thresB, 0);

    return min(aCompany, bCompany);
}

int main(void)
{
    int tcCnt;
<<<<<<< HEAD
    int fareA, baseB, thresB, fareB, liters;
=======
    int fareA, int baseB, int thresB, int fareB, int liters;
>>>>>>> 5fabc19129b67e54a0245e833081d305e778315e
    int minFare;
    std::cin >> tcCnt;

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        std::cin >> fareA >> baseB >> thresB >> fareB >> liters;
        minFare = tapWaterFare(fareA, baseB, thresB, fareB, liters);
        std::cout << "#" << tc << " " << minFare << std::endl;
    }

    return 0;
}