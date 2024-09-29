class Solution
{

private:
    long long int toChangeBit(int diff, vector<int> &v, int ind, int left)
    {
        if (ind == 31)
        {
            if (1 <= diff)
            {
                v[31] = 0;
            }
            return 1;
        }
        long long int ans = 0;
        if (v[ind + 1] == 0)
        {
            ans = pow(2, 31 - ind - 1);
        }
        ans += toChangeBit(diff, v, ind + 1, left);
        if (ans <= diff)
        {
            v[ind] = 0;
        }
        return ans;
    }

public:
    int rangeBitwiseAnd(int left, int right)
    {
        vector<int> v(32, 0);
        for (int i = 0; i < 32; i++)
        {
            v[i] = ((left & (1 << (31 - i))) == 0) ? 0 : 1;
        }
        toChangeBit(right - left, v, 0, left);
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            cout << v[i] << " ";
            ans += pow(2, 31 - i) * v[i];
        }
        cout << endl;
        return ans;
    }
};