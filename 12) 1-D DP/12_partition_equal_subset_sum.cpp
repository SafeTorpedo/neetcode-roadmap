#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int target = 0;

        for (int num : nums)
            target += num;

        if (target % 2 != 0)
            return false;

        target /= 2;

        unordered_set<int> dp;
        dp.insert(0);

        for (int i = 0; i < nums.size(); i++)
        {
            unordered_set<int> nextDp;
            for (auto it = dp.begin(); it != dp.end(); it++)
            {
                if (*it + nums[i] == target)
                    return true;

                nextDp.insert(*it + nums[i]);
                nextDp.insert(*it);
            }
            dp = nextDp;
        }

        return false;
    }
};