#include <cstdio>
#include <vector>

// Accumulated cost will be expressed in 1-index.
// The 0'th position will be a NIL, which has 0 as its vaule.

long long profit(std::vector<long long> &accumulated_cost, int purchase_date, int sell_date)
{
    long long cost = accumulated_cost[sell_date - 1] - accumulated_cost[purchase_date - 1];
    long long sellPrice = accumulated_cost[sell_date] - accumulated_cost[sell_date - 1];
    int purchasedUnits = sell_date - purchase_date;
    return sellPrice * purchasedUnits - cost;
}

long long findMaxProfit(std::vector<long long> &accumulated_cost, int sold_date)
{
    if (sold_date == accumulated_cost.size() - 1)
        return 0;
    
    int maxProfitDay;
    long long maxProfit = -1, profit_;
    for (int i = accumulated_cost.size() - 1; i > sold_date; i--)
    {
        profit_ = profit(accumulated_cost, sold_date + 1, i);
        if (profit_ > maxProfit)
        {
            maxProfit = profit_;
            maxProfitDay = i;
        }
    }
    return maxProfit + findMaxProfit(accumulated_cost, maxProfitDay);
}

int main(void)
{
    freopen("input.txt", "r", stdin);

    int tcCnt;
    scanf("%d", &tcCnt);

    int days;
    long long price;
    std::vector<long long> accumulatedCost;

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%d", &days);
        accumulatedCost.resize(days + 1);
        accumulatedCost[0] = 0;
        
        for (int i = 1; i < accumulatedCost.size(); i++)
        {
            scanf("%lld", &price);
            accumulatedCost[i] = accumulatedCost[i - 1] + price;
        }
        
        printf("#%d %lld \n", tc, findMaxProfit(accumulatedCost, 0));
    }
}
