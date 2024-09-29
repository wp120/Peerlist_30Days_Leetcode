class Solution
{

private:
    int getBit(int &left, int i)
    {
        return (left & (1 << i)) == 0 ? 0 : 1;
    }

    void setBit(int &left, int i)
    {
        left = (left | (1 << i));
    }

    void clearBit(int &left, int i)
    {
        int j = (1 << i);
        left = left & (~j);
    }

    long long int toChangeBit(int diff, int ind, int &left)
    {
        if (ind == 31)
        {
            if (1 <= diff)
            {
                clearBit(left, 0);
            }
            return 1;
        }
        long long int ans = 0;
        if (getBit(left, 31 - ind - 1) == 0)
        {
            ans = pow(2, 31 - ind - 1);
        }
        ans += toChangeBit(diff, ind + 1, left);
        if (ans <= diff)
        {
            clearBit(left, 31 - ind);
        }
        return ans;
    }

public:
    int rangeBitwiseAnd(int left, int right)
    {
        toChangeBit(right - left, 0, left);
        return left;
    }
};