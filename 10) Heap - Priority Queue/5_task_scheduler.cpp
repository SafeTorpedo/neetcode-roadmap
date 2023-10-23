#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> count(26);
        queue<vector<int>> q;
        priority_queue<int> pq;

        for (char task : tasks)
            count[task - 'A']++;

        for (int i = 0; i < 26; i++)
        {
            if (count[i] > 0)
                pq.push(count[i]);
        }

        int time = 0;
        while (!q.empty() || !pq.empty())
        {
            time++;

            if (!pq.empty())
            {
                if (pq.top() - 1 > 0)
                    q.push({pq.top() - 1, time + n});

                pq.pop();
            }

            if (!q.empty() && q.front()[1] == time)
            {
                pq.push(q.front()[0]);
                q.pop();
            }
        }

        return time;
    }
};