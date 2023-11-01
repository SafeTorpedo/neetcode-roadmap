#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, vector<int>> mp;

        for (auto course : prerequisites)
            mp[course[0]].push_back(course[1]);

        unordered_set<int> visited;

        for (int course = 0; course < numCourses; course++)
        {
            if (!dfs(course, mp, visited))
                return false;
        }

        return true;
    }

private:
    bool dfs(int course, unordered_map<int, vector<int>> &mp, unordered_set<int> &visited)
    {
        if (visited.find(course) != visited.end())
            return false;

        if (mp[course].empty())
            return true;

        visited.insert(course);

        for (int i = 0; i < mp[course].size(); i++)
        {
            int nextCourse = mp[course][i];
            if (!dfs(nextCourse, mp, visited))
                return false;
        }

        mp[course].clear();
        visited.erase(course);
        return true;
    }
};