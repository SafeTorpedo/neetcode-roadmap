#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        int option1 = helper(nums, 0, n - 2);
        int option2 = helper(nums, 1, n - 1);

        return max(option1, option2);
    }

private:
    int helper(vector<int> &nums, int start, int end)
    {
        int prev = 0, curr = 0, next = 0;

        for (int i = start; i <= end; i++)
        {
            next = max(prev + nums[i], curr);
            prev = curr;
            curr = next;
        }

        return curr;
    }
};