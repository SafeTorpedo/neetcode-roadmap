#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> ans;

        int i = 0, j = 0;
        while (j < nums.size())
        {
            while (!dq.empty() && nums[j] > nums[dq.back()])
                dq.pop_back();

            dq.push_back(j);

            if (j + 1 >= k)
            {
                ans.push_back(nums[dq.front()]);
                i++;
            }

            if (i > dq.front())
            {
                dq.pop_front();
            }

            j++;
        }
        return ans;
    }
};