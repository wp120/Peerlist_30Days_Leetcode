class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> index;
        // We can use normal (ordered) map as well but
        // average tc for unordered_map is O(1);
        for (int i = 0; i < nums.size(); i++)
        {
            // target-nums[i] is the another number needed to make target.
            if (index[target - nums[i]] != 0)
            { // It means another needed number has been found.
                return {index[target - nums[i]] - 1, i};
            }
            index[nums[i]] = i + 1;
            // we are using one-based indexing because default value for int,int map is always zero.
        }
        return {-1, -1}; // This line will never be executed because each input has exactly one solution.
    }
};