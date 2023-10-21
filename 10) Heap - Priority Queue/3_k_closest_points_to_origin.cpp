#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, vector<int>>> pq;
        vector<vector<int>> ans;

        for (auto point : points)
        {
            int distance = pow(point[0], 2) + pow(point[1], 2);
            pq.push({distance, point});

            if (pq.size() > k)
                pq.pop();
        }

        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};