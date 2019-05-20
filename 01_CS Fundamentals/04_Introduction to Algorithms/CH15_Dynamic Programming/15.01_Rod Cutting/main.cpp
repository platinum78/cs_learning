#include <iostream>
#include <vector>
#include <ctime>

#include "cut_rod.h"
#include "./memoized_cut_rod.h"
#include "./bottom_up_cut_rod.h"

int main(void)
{
    int rodInitLen;
    std::cin >> rodInitLen;

    std::vector<int> priceByLen({ 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 });
    // int maxRevenue = cutRod(priceByLen, rodInitLen);
    // int maxRevenue = memoizedCutRod(priceByLen, rodInitLen);
    int maxRevenue = bottomUpCutRod(priceByLen, rodInitLen);

    std::cout << "Maximum revenue for rod with length " << rodInitLen << ": ";
    std::cout << maxRevenue << std::endl;
}