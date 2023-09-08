#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int m = s1.size(), n = s2.size();
        if (m > n)
            return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        for (char c : s1)
            freq1[c - 'a']++;

        int i = 0, j = 0;
        while (j < n)
        {
            freq2[s2[j] - 'a']++;

            if (j - i + 1 < m)
                j++;
            else if (j - i + 1 == m && freq1 == freq2)
                return true;
            else
            {
                freq2[s2[i] - 'a']--;
                i++, j++;
            }
        }
        return false;
    }
};