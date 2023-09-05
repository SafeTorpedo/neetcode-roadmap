#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();

        if (m > n)
            return findMedianSortedArrays(nums2, nums1);

        int total = m + n;
        int left = 0, right = m;
        double ans;

        while (left <= right)
        {
            int len1 = (left + right) / 2;
            int len2 = (total + 1) / 2 - len1;

            int l1 = len1 > 0 ? nums1[len1 - 1] : INT_MIN;
            int l2 = len2 > 0 ? nums2[len2 - 1] : INT_MIN;
            int r1 = len1 < m ? nums1[len1] : INT_MAX;
            int r2 = len2 < n ? nums2[len2] : INT_MAX;

            if (l1 <= r2 && l2 <= r1)
            {
                if (total % 2 == 0)
                    ans = (max(l1, l2) + min(r1, r2)) / 2.0;
                else
                    ans = max(l1, l2);

                break;
            }
            else if (l1 > r2)
                right = len1 - 1;
            else
                left = len1 + 1;
        }

        return ans;
    }
};