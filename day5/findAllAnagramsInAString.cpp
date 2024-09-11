class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> answer;
        if (s.size() < p.size())
        {
            return answer;
        }
        vector<int> freq(26, 0);
        int nonZero = 0; // for checking the number of non-zero elements in freq vector;

        // filling the freq vector for string p;
        for (int i = 0; i < p.size(); i++)
        {
            freq[p[i] - 'a']++;
            if (freq[p[i] - 'a'] == 1)
            {
                nonZero++;
            }
        }

        // checking for first window of length p.size() at the start of s;
        for (int i = 0; i < p.size(); i++)
        {
            freq[s[i] - 'a']--;
            if (freq[s[i] - 'a'] == 0)
            {
                nonZero--;
            }
            if (freq[s[i] - 'a'] == -1)
            {
                nonZero++;
            }
        }
        if (nonZero == 0)
        {
            answer.push_back(0);
        }

        // now sliding the window towards the end of s;
        for (int i = p.size(); i < s.size(); i++)
        {
            freq[s[i - p.size()] - 'a']++;
            if (freq[s[i - p.size()] - 'a'] == 0)
            {
                nonZero--;
            }
            if (freq[s[i - p.size()] - 'a'] == 1)
            {
                nonZero++;
            }
            freq[s[i] - 'a']--;
            if (freq[s[i] - 'a'] == 0)
            {
                nonZero--;
            }
            if (freq[s[i] - 'a'] == -1)
            {
                nonZero++;
            }
            if (nonZero == 0)
            {
                answer.push_back(i - p.size() + 1);
            }
        }
        return answer;
    }
};