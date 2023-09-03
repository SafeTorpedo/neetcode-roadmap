#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans;
        int left=0, right=nums.size()-1;
        while (left<=right){
            if (nums[left]<nums[right]){
                ans=min(nums[left], ans);
                break;
            }

            int mid=(left+right)/2;
            ans=min(ans, nums[mid]);
            if (nums[mid]>=nums[left])
                left=mid+1;
            else
                right=mid-1;
        }
        return ans;
    }
};