class Solution
{

    int makeChange(vector<int> &coins, int ind, int amount, vector<vector<int>> &dp)
    {
        int n = coins.size();
        if (amount == 0)
        {
            return 0;
        }
        if (ind == n)
        {
            return -1; // it means we couldn't make amount.
        }
        if (dp[ind][amount] != -2)
        {
            return dp[ind][amount];
        }
        dp[ind][amount] = INT_MAX;
        // we either take that coin or don't take.
        if (coins[ind] <= amount)
        {                                                                // we can take coin only if it's value is less than amount.
            int taken = makeChange(coins, ind, amount - coins[ind], dp); // we take that coin
            // note that if we take that coin then we don't increase ind because we may take that coin again
            if (taken != -1)
            {
                dp[ind][amount] = min(dp[ind][amount], 1 + taken);
            }
        }
        int notTaken = makeChange(coins, ind + 1, amount, dp); // we don't take that coin
        // note that if we don't take then we increase ind because in future also we won't take it.
        // Because if we take it in future then we will calculate same combinations again and again.
        if (notTaken != -1)
        {
            dp[ind][amount] = min(dp[ind][amount], notTaken);
        }
        if (dp[ind][amount] == INT_MAX)
        {
            return dp[ind][amount] = -1;
        }
        return dp[ind][amount];
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -2));
        return makeChange(coins, 0, amount, dp);
    }
};