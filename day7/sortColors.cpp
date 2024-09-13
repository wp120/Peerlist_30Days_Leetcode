class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0, j = -1, k = n;
        // i is for iterating
        // all indices to the left of j (including j) are for 0
        // all indices to the right of k (including k) are for 2
        while (i < k)
        {
            if (nums[i] == 0)
            {
                // shiting this zero to the left
                j++;
                swap(nums[i], nums[j]);
                i++;
            }
            else if (nums[i] == 2)
            {
                // shifting this 2 to the right
                k--;
                swap(nums[i], nums[k]);
            }
            else
            {
                // if one then do nothing
                i++;
            }
        }
        return;
    }
};