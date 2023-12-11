#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int m = t.length();
        int n = s.length();

        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[0][i] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                dp[j][i] = dp[j][i - 1] + (t[j - 1] == s[i - 1] ? dp[j - 1][i - 1] : 0);
        }

        return dp[m][n];
    }
};