#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        vector<pair<int, int>> info;
        int n = position.size(), i;
        for (i = 0; i < n; i++)
            info.push_back({position[i], speed[i]});

        sort(info.begin(), info.end());
        stack<float> s;

        float time;
        for (auto i : info)
        {
            time = (float)(target - i.first) / (float)i.second;
            if (s.empty())
                s.push(time);
            else if (s.top() <= time)
            {
                while (!s.empty() && s.top() <= time)
                    s.pop();

                s.push(time);
            }
            else
                s.push(time);
        }

        return s.size();
    }
};