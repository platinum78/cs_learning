#include <vector>

int memoizedCutRod(std::vector<int> &prices, int length);
int memoizedCutRod_aux(std::vector<int> &prices, std::vector<int> &revenue_by_length, int length);

int memoizedCutRod(std::vector<int> &prices, int length)
{
    std::vector<int> maxRevenueByLength(length + 1, -1);
    return memoizedCutRod_aux(prices, maxRevenueByLength, length);
}

int memoizedCutRod_aux(std::vector<int> &prices, std::vector<int> &revenue_by_price, int length)
{
    if (revenue_by_price[length] >= 0)
        return revenue_by_price[length];
    
    if (length == 0)
        return 0;
    
    int maxRevenue = -1;
    int revenue;
    for (int i = 1; i <= length && i < prices.size(); i++)
    {
        revenue = prices[i] + memoizedCutRod_aux(prices, revenue_by_price, length - i);
        if (revenue > maxRevenue)
        {
            maxRevenue = revenue;
            revenue_by_price[length] = maxRevenue;
        }
    }

    return maxRevenue;
}