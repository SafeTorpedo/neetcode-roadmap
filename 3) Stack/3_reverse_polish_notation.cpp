#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        int op1, op2;
        stack<int> s;
        for (string i : tokens)
        {
            if (i == "+" || i == "-" || i == "*" || i == "/")
            {
                op2 = s.top();
                s.pop();
                op1 = s.top();
                s.pop();
                s.push(helper(op1, i, op2));
            }
            else
                s.push(stoi(i));
        }
        return s.top();
    }

    int helper(long op1, string op, long op2)
    {
        if (op == "+")
            return op1 + op2;
        else if (op == "-")
            return op1 - op2;
        else if (op == "*")
            return op1 * op2;
        else
            return op1 / op2;
    }
};