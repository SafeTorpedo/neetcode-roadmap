#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int arr[26] = {0};

        if (s.size() != t.size())
            return false;

        for (char ch : s)
            arr[ch - 97]++;

        for (char ch : t)
        {
            arr[ch - 97]--;
            if (arr[ch - 97] < 0)
                return false;
        }
        return true;
    }
};