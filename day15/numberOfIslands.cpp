class Solution
{
private:
    // Function that covers an island.
    //(By cover I mean changin '1' to '2', so next time we visit that Island, we know it's already visited)
    void coverIsland(int r, int c, vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] != '1') // checking if given cell is valid and if it an uncovered island
        {
            return;
        }
        grid[r][c] = '2';
        // now getting adjacent cells
        int rChanges[4] = {-1, 0, 1, 0};
        int cChanges[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int newR = r + rChanges[i];
            int newC = c + cChanges[i];
            coverIsland(newR, newC, grid);
        }
        return;
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                { // once we find a new island, we will cover it entirely.
                    count++;
                    coverIsland(i, j, grid);
                }
            }
        }
        return count;
    }
};