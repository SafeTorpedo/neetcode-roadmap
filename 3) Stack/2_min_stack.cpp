#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    MinStack()
    {
    }

    void push(int val)
    {
        st.push(val);

        if (minSt.empty() || val < minSt.top().first)
        {
            minSt.push({val, 1});
        }
        else if (val == minSt.top().first)
        {
            minSt.top().second++;
        }
    }

    void pop()
    {
        if (st.top() == minSt.top().first)
        {
            minSt.top().second--;
            if (minSt.top().second == 0)
            {
                minSt.pop();
            }
        }
        st.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return minSt.top().first;
    }

private:
    stack<int> st;
    stack<pair<int, int>> minSt;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */