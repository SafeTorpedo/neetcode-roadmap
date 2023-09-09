#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int m = s.size(), n = t.size();

        if (n > m)
            return "";

        unordered_map<char, int> mp;
        for (char c : t)
            mp[c]++;

        int i = 0, j = 0, ctr = n, start = 0, len = INT_MAX;
        while (j < m)
        {
            if (mp[s[j]] > 0)
                ctr--;

            mp[s[j]]--;
            j++;

            while (ctr == 0)
            {
                if (j - i < len)
                    start = i, len = j - i;

                mp[s[i]]++;
                if (mp[s[i]] > 0)
                    ctr++;

                i++;
            }
        }
        if (len != INT_MAX)
            return s.substr(start, len);

        return "";
    }
};