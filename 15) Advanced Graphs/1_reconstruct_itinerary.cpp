#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        unordered_map<string, multiset<string>> m;
        for (int i = 0; i < tickets.size(); i++)
            m[tickets[i][0]].insert(tickets[i][1]);

        vector<string> ans;
        dfs(m, "JFK", ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }

private:
    void dfs(unordered_map<string, multiset<string>> &m, string airport, vector<string> &ans)
    {
        while (!m[airport].empty())
        {
            string next = *m[airport].begin();
            m[airport].erase(m[airport].begin());
            dfs(m, next, ans);
        }

        ans.push_back(airport);
    }
};