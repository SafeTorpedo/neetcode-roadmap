#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;

        int i = 0;
        while (i < n - 1)
        {
            if (i + nums[i] >= n - 1)
            {
                ans++;
                break;
            }

            int maxIndex = i + 1;
            int maxValue = 0;

            for (int j = i + 1; j < i + 1 + nums[i]; j++)
            {
                if (j + nums[j] > maxValue)
                {
                    maxIndex = j;
                    maxValue = j + nums[j];
                }
            }

            i = maxIndex;
            ans++;
        }

        return ans;
    }
};