#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector <vector<int>> ans;
        vector <int> temp;
        backtrack(candidates, ans, temp, target, 0);
        return ans;
    }

private:
    void backtrack(vector<int>& candidates, vector <vector<int>>& ans, vector<int>& temp, int target, int i){
        if (i>=candidates.size() || target<0)
            return;

        if (target==0){
            ans.push_back(temp);
            return;
        }

        temp.push_back(candidates[i]);
        backtrack(candidates, ans, temp, target-candidates[i], i);

        temp.pop_back();
        backtrack(candidates, ans, temp, target, i+1);
    }
};