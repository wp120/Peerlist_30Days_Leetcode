class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int i = 0, j = nums.size() - 1;
        // Normal binary search is modified as follows
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            // we break the rotated sorted array into two parts
            // i to mid-1 is the left part
            // mid+1 to j is the right part
            // By observation and common sense, either of left or right part will be unrotated and other will be rotated
            // Now we can check if target exists in unrotated part just by looking at that part's starting and ending point
            // If it doesn't exist there then we will try finding it in unrotated part
            if (nums[i] <= nums[mid])
            { // If left part is unrotated then
                if (nums[i] <= target && target <= nums[mid])
                { // Check if target exists there and if yes continue searching in that part
                    j = mid - 1;
                }
                else
                { // Else continue in other (right) part which is rotated.
                    i = mid + 1;
                }
            }
            else
            { // If right part is unrotated then
                if (nums[mid] <= target && target <= nums[j])
                { // Check if target exists there and if yes continue searching in that part
                    i = mid + 1;
                }
                else
                { // Else continue in other (left) part which is rotated.
                    j = mid - 1;
                }
            }
        }
        return -1;
    }
};