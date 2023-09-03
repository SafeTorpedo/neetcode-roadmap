#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int ans=*max_element(piles.begin(), piles.end());

        if (n==h)
            return ans;

        int low=0, high=ans;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            double hours = 0;
            for (int i = 0; i < n; i++) {
                hours += ceil((double) piles[i] / mid);
            }
            if (hours <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};