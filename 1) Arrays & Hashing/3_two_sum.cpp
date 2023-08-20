#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> m;
        int sub;
        for (int i = 0; i < nums.size(); i++)
        {
            sub = target - nums[i];
            if (m.find(sub) != m.end())
                return {m[sub], i};

            m[nums[i]] = i;
        }
        return {};
    }
};