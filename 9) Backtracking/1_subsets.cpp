#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(ans, temp, nums, 0);
        return ans;
    }

private:
    void backtrack(vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums, int i)
    {
        if (i == nums.size())
            ans.push_back(temp);
        else
        {
            temp.push_back(nums[i]);
            backtrack(ans, temp, nums, i + 1);

            temp.pop_back();
            backtrack(ans, temp, nums, i + 1);
        }
    }
};