#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack <pair<int, int>> st;
        int ans=0, start, height, n=heights.size();
        for (int i=0; i<n; i++){
            start=i;
            while (!st.empty() && st.top().second>heights[i]){
                start=st.top().first;
                height=st.top().second;
                ans=max(ans, height*(i-start));
                st.pop();
            }

            st.push({start, heights[i]});
        }

        while(!st.empty()){
            start=st.top().first;
            height=st.top().second;
            ans=max(ans, height*(n-start));
            st.pop();
        }
        return ans;
    }
};