#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int ans = 0, i = 0, j = height.size() - 1, l_max = 0, r_max = 0;
        while (i < j)
        {
            if (height[i] <= height[j])
            {
                l_max = max(l_max, height[i]);
                ans += l_max - height[i];
                i++;
            }
            else
            {
                r_max = max(r_max, height[j]);
                ans += r_max - height[j];
                j--;
            }
        }
        return ans;
    }
};