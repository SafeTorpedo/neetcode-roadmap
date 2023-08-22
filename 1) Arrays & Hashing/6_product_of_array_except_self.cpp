#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int i, n = nums.size();
        vector<int> ans(n);
        ans[0] = 1;
        for (i = 1; i < n; i++)
            ans[i] = ans[i - 1] * nums[i - 1];

        int temp = nums[n - 1];
        for (i = n - 2; i >= 0; i--)
        {
            ans[i] = ans[i] * temp;
            temp = temp * nums[i];
        }

        return ans;
    }
};