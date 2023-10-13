#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
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
            int next = i;
            while (next < nums.size() - 1 && nums[next] == nums[next + 1])
                next++;
            backtrack(ans, temp, nums, next + 1);
        }
    }
};