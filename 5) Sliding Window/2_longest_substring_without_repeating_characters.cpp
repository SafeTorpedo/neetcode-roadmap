#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chars;
        int i=0, j=0, ans=0;
        while (j<s.size()){
            if (chars.find(s[j])==chars.end()){
                chars.insert(s[j]);
                ans=max(ans, j-i+1);
                j++;
            }
            else{
                chars.erase(s[i]);
                i++;    
            }
        }
        return ans;
    }
};