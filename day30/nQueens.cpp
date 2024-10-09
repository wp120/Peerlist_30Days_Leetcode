class Solution
{

    bool isSafe(int i, int j, int n, vector<string> &board)
    { // this function checks if queen can be placed at i,j without being attacked.
        int k = i - 1;
        while (k >= 0)
        { // checking in upper column
            if (board[k][j] == 'Q')
            {
                return false;
            }
            k--;
        }
        k = i - 1;
        int l = j - 1;
        while (k >= 0 && l >= 0)
        { // checking in upper left diagonal
            if (board[k][l] == 'Q')
            {
                return false;
            }
            k--;
            l--;
        }
        k = i - 1;
        l = j + 1;
        while (k >= 0 && l < n)
        { // checking in upper right diagonal
            if (board[k][l] == 'Q')
            {
                return false;
            }
            k--;
            l++;
        }
        // no need to check in other directions because of our method of placement
        return true;
    }

    void placeQueens(int i, int n, vector<string> &board, vector<vector<string>> &ans)
    { // i is row number
        // This function checks for safe places in one row and places queen in that row. Then calls fuction again for next row.
        // Below is base case i.e. if i==n means we placed queen in every row.
        if (i == n)
        {
            ans.push_back(board);
            return;
        }
        for (int j = 0; j < n; j++)
        { // checking for safe places in ith row.
            if (isSafe(i, j, n, board))
            {
                board[i][j] = 'Q';
                placeQueens(i + 1, n, board, ans); // calling function for next row.
                board[i][j] = '.';
            }
        }
        return;
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board;
        for (int i = 0; i < n; i++)
        {
            string s;
            for (int j = 0; j < n; j++)
            {
                s += ".";
            }
            board.push_back(s);
        }
        placeQueens(0, n, board, ans);
        return ans;
    }
};