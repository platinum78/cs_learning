#include <iostream>
#include <vector>

int cutRod(std::vector<int> &prices, int n)
{
    if (n == 0)
        return 0;
    
    int maxRevenue = -1;
    int revenue;
    for (int i = 1; i <= n && i < prices.size(); i++)
    {
        revenue = prices[i] + cutRod(prices, n - i);
        maxRevenue = (revenue > maxRevenue ? revenue : maxRevenue);
    }
    
    return maxRevenue;
}