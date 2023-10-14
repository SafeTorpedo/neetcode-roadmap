#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, ans, temp, target, 0);
        return ans;
    }

private:
    void backtrack(vector<int> &candidates, vector<vector<int>> &ans, vector<int> &temp, int target, int i)
    {
        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }

        if (i >= candidates.size() || target < 0)
            return;

        temp.push_back(candidates[i]);
        backtrack(candidates, ans, temp, target - candidates[i], i + 1);

        temp.pop_back();
        int next = i;
        while (next < candidates.size() - 1 && candidates[next] == candidates[next + 1])
            next++;
        backtrack(candidates, ans, temp, target, next + 1);
    }
};