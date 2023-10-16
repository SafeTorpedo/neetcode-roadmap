#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> temp;
        backtrack(ans, temp, s, 0);
        return ans;
    }

private:
    void backtrack(vector<vector<string>> &ans, vector<string> &temp, string s, int start)
    {
        if (start == s.size())
        {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i < s.size(); i++)
        {
            if (isPalindrome(s, start, i))
            {
                string str = s.substr(start, i - start + 1);
                temp.push_back(str);

                backtrack(ans, temp, s, i + 1);
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int left, int right)
    {
        while (left < right)
        {
            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }
};