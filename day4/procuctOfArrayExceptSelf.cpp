class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> answer(n, 1);
        for (int i = 1; i < n; i++)
        { // for storing product of all elements on the left.
            answer[i] = answer[i - 1] * nums[i - 1];
        }
        int rightMult = 1; // for storing product of all elements on the right.
        for (int i = n - 2; i >= 0; i--)
        {
            rightMult *= nums[i + 1];
            answer[i] *= rightMult; // Multiplying product of all left with product of all right elements.
        }
        return answer;
    }
};