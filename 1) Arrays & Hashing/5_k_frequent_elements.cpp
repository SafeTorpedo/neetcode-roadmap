#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        for (int i : nums)
            m[i]++;

        priority_queue<p, vector<p>, greater<p>> pq;

        for (auto i : m)
        {
            pq.push({i.second, i.first});
            if (pq.size() > k)
                pq.pop();
        }

        vector<int> ans;
        p temp;
        while (!pq.empty())
        {
            temp = pq.top();
            pq.pop();
            ans.push_back(temp.second);
        }
        return ans;
    }
};