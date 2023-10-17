#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};

        unordered_map<char, string> m = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};

        string temp = "";
        vector<string> ans;

        backtrack(ans, temp, digits, 0, m);
        return ans;
    }

private:
    void backtrack(vector<string> &ans, string &temp, string digits, int index, unordered_map<char, string> &m)
    {
        if (index == digits.size())
        {
            ans.push_back(temp);
            return;
        }

        string str = m[digits[index]];
        for (int i = 0; i < str.size(); i++)
        {
            temp.push_back(str[i]);
            backtrack(ans, temp, digits, index + 1, m);
            temp.pop_back();
        }
    }
};