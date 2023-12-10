#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        m = matrix.size();
        n = matrix[0].size();

        memset(path, 0, sizeof(path));

        int max_path = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                max_path = max(max_path, dfs(i, j, matrix));
        }

        return max_path;
    }

private:
    int m, n;
    short path[200][200];

    int dfs(int i, int j, vector<vector<int>> &matrix)
    {
        if (path[i][j] > 0)
            return path[i][j];

        if (path[i][j] == -1)
            return 0;

        int next_max = 0;
        path[i][j] = -1;

        if (i > 0 && matrix[i][j] < matrix[i - 1][j])
            next_max = max(next_max, dfs(i - 1, j, matrix));

        if (j > 0 && matrix[i][j] < matrix[i][j - 1])
            next_max = max(next_max, dfs(i, j - 1, matrix));

        if (i < m - 1 && matrix[i][j] < matrix[i + 1][j])
            next_max = max(next_max, dfs(i + 1, j, matrix));

        if (j < n - 1 && matrix[i][j] < matrix[i][j + 1])
            next_max = max(next_max, dfs(i, j + 1, matrix));

        return path[i][j] = 1 + next_max;
    }
};