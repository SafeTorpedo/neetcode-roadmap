#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int j, k, sum, n = nums.size();

        for (int i = 0; i < n - 2; i++)
        {
            if (nums[i] > 0)
                return ans;

            if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
            {
                j = i + 1, k = n - 1, sum = 0 - nums[i];
                while (j < k)
                {
                    if (nums[j] + nums[k] == sum)
                    {
                        ans.push_back({nums[i], nums[j], nums[k]});
                        while (j < k && nums[j] == nums[j + 1])
                            j++;

                        while (j < k && nums[k] == nums[k - 1])
                            k--;

                        j++;
                        k--;
                    }
                    else if (nums[j] + nums[k] < sum)
                        j++;
                    else
                        k--;
                }
            }
        }
        return ans;
    }
};