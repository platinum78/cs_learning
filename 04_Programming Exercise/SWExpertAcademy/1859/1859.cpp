#include <cstdio>
#include <vector>

// Accumulated cost will be expressed in 1-index.
// The 0'th position will be a NIL, which has 0 as its vaule.

long profit(std::vector<long> &accumulated_cost, int purchase_date, int sell_date)
{
    long cost = accumulated_cost[sell_date - 1] - accumulated_cost[purchase_date - 1];
    long sellPrice = accumulated_cost[sell_date] - accumulated_cost[sell_date - 1];
    int purchasedUnits = sell_date - purchase_date;
    long total_profit = sellPrice * purchasedUnits - cost;
    return sellPrice * purchasedUnits - cost;
}

long findMaxProfit(std::vector<long> &accumulated_cost, int days, int sold_date)
{
    printf("%d \n", sold_date);
    if (sold_date == days)
        return 0;
    
    int maxProfitDay;
    long maxProfit = -1, profit_;
    for (int i = days; i > sold_date; i--)
    {
        profit_ = profit(accumulated_cost, sold_date + 1, i);
        if (profit_ >= maxProfit)
        {
            maxProfit = profit_;
            maxProfitDay = i;
        }
    }
    return maxProfit + findMaxProfit(accumulated_cost, days, maxProfitDay);
}

int main(void)
{
    freopen("input.txt", "r", stdin);

    int tcCnt;
    scanf("%d", &tcCnt);

    int days;
    long price;
    std::vector<long> accumulatedCost(1000001);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%d", &days);
        printf("%d \n", days);
        accumulatedCost[0] = 0;
        
        for (int i = 1; i <= days; i++)
        {
            scanf("%ld", &price);
            accumulatedCost[i] = accumulatedCost[i - 1] + price;
        }
        
        printf("#%d %ld \n", tc, findMaxProfit(accumulatedCost, days, 0));
    }
}
