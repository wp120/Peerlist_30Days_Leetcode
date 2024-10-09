class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            if (matrix[0][i] == '1')
            {
                dp[0][i] = 1;
                maxArea = 1;
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == '1')
            {
                dp[i][0] = 1;
                maxArea = 1;
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == '1' && matrix[i][j - 1] == '1' && matrix[i - 1][j - 1] == '1' && matrix[i - 1][j] == '1')
                {
                    int s1 = min({dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    int s2 = min({dp[i - 1][j - 1], dp[i - 1][j]}) + 1;
                    dp[i][j] = max(1, min(s1, s2));
                    maxArea = max(maxArea, dp[i][j] * dp[i][j]);
                }
                else if (matrix[i][j] == '1')
                {
                    dp[i][j] = 1;
                    maxArea = max(maxArea, dp[i][j] * dp[i][j]);
                }
            }
        }
        return maxArea;
    }
};