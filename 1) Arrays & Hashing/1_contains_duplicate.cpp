#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        set<int> temp(nums.begin(), nums.end());

        if (nums.size() != temp.size())
            return true;

        return false;
    }
};