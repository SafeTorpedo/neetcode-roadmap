#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int current, ans = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for (int i : nums)
        {
            if (s.find(i - 1) == s.end())
            {
                current = 1;
                while (s.find(i + current) != s.end())
                {
                    current++;
                }
                ans = max(ans, current);
            }
        }
        return ans;
    }
};