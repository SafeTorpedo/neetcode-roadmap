#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> m;
        string temp;
        for (string s : strs)
        {
            temp = s;
            sort(s.begin(), s.end());
            m[s].push_back(temp);
        }

        vector<vector<string>> ans;
        for (auto it = m.begin(); it != m.end(); it++)
            ans.push_back(it->second);

        return ans;
    }
};