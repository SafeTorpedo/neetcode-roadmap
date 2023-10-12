#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(ans, temp, nums);
        return ans;
    }

private:
    void backtrack(vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums)
    {
        if (temp.size() == nums.size())
        {
            ans.push_back(temp);
            return;
        }

        for (int i : nums)
        {
            if (find(temp.begin(), temp.end(), i) != temp.end())
                continue;

            temp.push_back(i);

            backtrack(ans, temp, nums);

            temp.pop_back();
        }
    }
};