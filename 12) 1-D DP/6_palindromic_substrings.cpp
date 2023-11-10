#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        int ans = 0;

        for (int i = 0; i < s.size(); i++)
        {
            expandMiddle(s, i, i, ans);
            expandMiddle(s, i, i + 1, ans);
        }

        return ans;
    }

private:
    void expandMiddle(string s, int i, int j, int &ans)
    {
        while (i >= 0 && j < s.size() && s[i] == s[j])
        {
            ans++;
            i--;
            j++;
        }
    }
};