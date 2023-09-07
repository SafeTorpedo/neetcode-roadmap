#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        unordered_map<char, int> m;
        int maxFreq = 0, ans = 0, i = 0, j = 0;

        while (j < s.size())
        {
            m[s[j]]++;
            maxFreq = max(maxFreq, m[s[j]]);
            if (j - i + 1 - maxFreq > k)
            {
                m[s[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};