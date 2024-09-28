class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        map<int, int> sumExists;
        sumExists[0] = 1;
        int ans = 0;
        int s = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            s += nums[i];
            ans += sumExists[s - k];
            sumExists[s]++;
        }
        return ans;
    }
};