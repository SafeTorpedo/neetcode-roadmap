#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    ans = max(ans, dfs(grid, m, n, i, j));
            }
        }

        return ans;
    }

private:
    int dfs(vector<vector<int>> &grid, int m, int n, int i, int j)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
            return 0;

        grid[i][j] = 0;

        return 1 + dfs(grid, m, n, i - 1, j) + dfs(grid, m, n, i + 1, j) + dfs(grid, m, n, i, j - 1) + dfs(grid, m, n, i, j + 1);
    }
};