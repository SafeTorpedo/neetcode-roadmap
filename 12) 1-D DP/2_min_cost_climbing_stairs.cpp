#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        memset(dp, -1, sizeof(dp));
        return min(helper(0, cost), helper(1, cost));
    }

private:
    int dp[1001];

    int helper(int index, vector<int> &cost)
    {
        if (index >= cost.size())
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int option1 = helper(index + 1, cost);
        int option2 = helper(index + 2, cost);

        return dp[index] = min(option1, option2) + cost[index];
    }
};