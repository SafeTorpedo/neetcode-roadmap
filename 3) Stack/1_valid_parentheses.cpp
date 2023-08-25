#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        unordered_map<char, char> m = {
            {')', '('},
            {'}', '{'},
            {']', '['},
        };

        for (char c : s)
        {
            if (m.find(c) != m.end())
            {
                if (st.empty() || st.top() != m[c])
                    return false;

                st.pop();
            }
            else
                st.push(c);
        }
        return st.empty();
    }
};