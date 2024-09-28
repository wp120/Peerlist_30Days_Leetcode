class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int mx = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push({nums[i][0], i, 0});
            mx = max(mx, nums[i][0]);
        }
        vector<int> ans = {0, INT_MAX};
        int mn;
        while (pq.size() == nums.size())
        {
            vector<int> temp = pq.top();
            pq.pop();
            // cout<<"popped "<<temp[0]<<". ";
            mn = temp[0];
            // cout<<"min is "<<mn<<" and "<<"max is "<<mx<<endl;
            if (ans[1] - ans[0] > mx - mn)
            {
                ans = {mn, mx};
            }
            else if (ans[1] - ans[0] == mx - mn)
            {
                if (ans[0] > mn)
                {
                    ans = {mn, mx};
                }
            }
            if (temp[2] < nums[temp[1]].size() - 1)
            {
                pq.push({nums[temp[1]][temp[2] + 1], temp[1], temp[2] + 1});
                // cout<<"pushed "<<nums[temp[1]][temp[2]+1]<<endl;
                mx = max(nums[temp[1]][temp[2] + 1], mx);
            }
        }
        return ans;
    }
};