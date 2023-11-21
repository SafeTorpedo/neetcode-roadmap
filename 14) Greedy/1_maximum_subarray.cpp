#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int current = 0, ans = INT_MIN;
        for (int i : nums)
        {
            current = max(i, current + i);
            ans = max(ans, current);
        }
        return ans;
    }
};