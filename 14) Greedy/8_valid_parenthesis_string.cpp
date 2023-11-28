#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkValidString(string s)
    {
        int low = 0, high = 0;

        for (char ch : s)
        {
            if (ch == '(')
                low++;
            else
                low--;

            if (ch != ')')
                high++;
            else
                high--;

            if (high < 0)
                break;

            low = max(low, 0);
        }

        return low == 0;
    }
};