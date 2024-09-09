class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int currSum = 0;      // sum of current subarray
        int maxSum = nums[0]; // max sum among all subarrays;
        for (int i = 0; i < nums.size(); i++)
        {
            currSum += nums[i];
            maxSum = max(maxSum, currSum);
            if (currSum < 0)
            {                // negative currSum will decrease the total sum if combined with next contiguous subarray
                currSum = 0; // so we will not take this subarray into account
            }
        }
        return maxSum;
    }
};