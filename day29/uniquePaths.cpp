class Solution
{

    int findPaths(int i, int j, int m, int n, vector<vector<int>> &dp)
    {
        if (i == m - 1 && j == n - 1)
        { // we've reached the goal.
            return 1;
        }
        if (i >= m || j >= n)
        { // outside the grid, so no way.
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        return dp[i][j] = findPaths(i + 1, j, m, n, dp) + findPaths(i, j + 1, m, n, dp);
    }

public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return findPaths(0, 0, m, n, dp);
    }
};