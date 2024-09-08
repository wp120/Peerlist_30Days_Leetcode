class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        int minTillNow = prices[0];
        // minTillNow is minimum price of stock till yesterday.
        for (int i = 1; i < prices.size(); i++)
        {
            int currProfit = prices[i] - minTillNow;
            // currProfit is max profit we can get if stock is sold on ith day.
            profit = max(profit, currProfit);
            // need not to care even if currProfit is negative because profit is initialized with zero.
            minTillNow = min(minTillNow, prices[i]);
        }
        return profit;
    }
};