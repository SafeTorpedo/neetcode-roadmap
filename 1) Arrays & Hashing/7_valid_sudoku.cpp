#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_set<string> s;
        char element;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                element = board[i][j];
                if (element == '.')
                    continue;

                // row insert
                if (!s.insert("r" + to_string(i) + element).second)
                    return false;

                // column insert
                if (!s.insert("c" + to_string(j) + element).second)
                    return false;

                // box insert
                if (!s.insert("b" + to_string(((i / 3) * 3) + (j / 3)) + element).second)
                    return false;
            }
        }
        return true;
    }
};