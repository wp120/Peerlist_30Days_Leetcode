class MinStack
{

    vector<int> v;
    int minIndex;

public:
    MinStack()
    {
        minIndex = -1;
    }

    void push(int val)
    {
        v.push_back(val);
        if (minIndex == -1)
        {
            minIndex = 0;
        }
        else if (v[minIndex] > val)
        {
            minIndex = v.size() - 1;
        }
    }

    void pop()
    {
        v.pop_back();
        if (v.empty())
        {
            minIndex = -1;
        }
        else
        {
            minIndex = 0;
            for (int i = 0; i < v.size(); i++)
            {
                if (v[minIndex] > v[i])
                {
                    minIndex = i;
                }
            }
        }
    }

    int top()
    {
        if (v.size() == 0)
        {
            return -1;
        }
        return v[v.size() - 1];
    }

    int getMin()
    {
        return minIndex == -1 ? -1 : v[minIndex];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */