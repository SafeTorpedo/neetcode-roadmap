#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, vector<int>> mp;

        for (auto course : prerequisites)
            mp[course[0]].push_back(course[1]);

        unordered_set<int> visited;
        unordered_set<int> cycle;

        vector<int> ans;

        for (int course = 0; course < numCourses; course++)
        {
            if (!dfs(course, mp, visited, cycle, ans))
                return {};
        }

        return ans;
    }

private:
    bool dfs(int course, unordered_map<int, vector<int>> &mp, unordered_set<int> &visited, unordered_set<int> &cycle, vector<int> &ans)
    {
        if (cycle.find(course) != cycle.end())
            return false;

        if (visited.find(course) != visited.end())
            return true;

        cycle.insert(course);

        for (int i = 0; i < mp[course].size(); i++)
        {
            int nextCourse = mp[course][i];
            if (!dfs(nextCourse, mp, visited, cycle, ans))
                return false;
        }

        cycle.erase(course);
        visited.insert(course);
        ans.push_back(course);
        return true;
    }
};