#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size(), current = 0;
        int actual = (n * (n + 1)) / 2;
        for (int i : nums)
            current += i;

        return actual - current;
    }
};