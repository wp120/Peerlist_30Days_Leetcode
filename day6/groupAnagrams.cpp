class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, vector<string>> mp;
        for (string s : strs)
        { // for each string
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end()); // make it's sorted string
            mp[sortedS].push_back(s);             // push it to vector of anagrams of that sorted string.
        }
        // lastly convert map to vector of strings.
        vector<vector<string>> ans;
        for (auto i : mp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};