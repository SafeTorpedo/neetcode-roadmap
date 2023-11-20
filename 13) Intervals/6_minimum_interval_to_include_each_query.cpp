#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &queries)
    {
        vector<int> sortedQueries = queries;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> m;

        sort(intervals.begin(), intervals.end());
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> ans;

        int i = 0;
        for (int j = 0; j < sortedQueries.size(); j++)
        {
            int query = sortedQueries[j];

            while (i < intervals.size() && intervals[i][0] <= query)
            {
                int left = intervals[i][0];
                int right = intervals[i][1];

                pq.push({right - left + 1, right});
                i++;
            }

            while (!pq.empty() && pq.top().second < query)
                pq.pop();

            if (!pq.empty())
                m[query] = pq.top().first;
            else
                m[query] = -1;
        }

        for (int j = 0; j < queries.size(); j++)
            ans.push_back(m[queries[j]]);

        return ans;
    }
};