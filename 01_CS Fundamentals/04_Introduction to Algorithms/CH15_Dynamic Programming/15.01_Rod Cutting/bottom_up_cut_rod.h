#include <vector>

int bottomUpCutRod(std::vector<int> &prices, int length)
{
    std::vector<int> revenue_by_length(length + 1);

    int revenue, maxRevenue;
    for (int total_len = 1; total_len <= length; total_len++)
    {
        maxRevenue = -1;
        for (int segment_len = 1; segment_len <= total_len; segment_len++)
        {
            revenue = prices[segment_len] + revenue_by_length[total_len - segment_len];
            if (revenue > maxRevenue)
            {
                maxRevenue = revenue;
                revenue_by_length[total_len] = maxRevenue;
            }
        }
    }

    return revenue_by_length[length];
}