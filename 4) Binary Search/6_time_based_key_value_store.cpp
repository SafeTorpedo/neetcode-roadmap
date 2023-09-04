#include <bits/stdc++.h>
using namespace std;

class TimeMap
{
public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        m[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp)
    {
        if (m.find(key) == m.end())
            return "";

        int left = 0, right = m[key].size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (m[key][mid].second == timestamp)
                return m[key][mid].first;
            else if (m[key][mid].second < timestamp)
                left = mid + 1;
            else
                right = mid - 1;
        }

        if (right >= 0)
            return m[key][right].first;

        return "";
    }

private:
    unordered_map<string, vector<pair<string, int>>> m;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */