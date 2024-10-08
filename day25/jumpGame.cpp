class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int mxJump = 0; // maximum jump we could've selected from previous indices.
        int rem = 0;    // remaining jumps
        for (int i = 0; i < nums.size() - 1; i++)
        {
            mxJump = max(mxJump, nums[i]);
            if (rem == 0)
            {
                if (mxJump == 0)
                {
                    return false;
                }
                rem = mxJump - 1;
            }
            else
            {
                rem--;
            }
            mxJump--; // important
        }
        return true;
    }
};