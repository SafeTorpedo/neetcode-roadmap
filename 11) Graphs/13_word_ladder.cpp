#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> dict;
        for (string word : wordList)
            dict.insert(word);

        queue<string> q;
        q.push(beginWord);

        int ans = 1;
        while (!q.empty())
        {
            int ctr = q.size();

            for (int i = 0; i < ctr; i++)
            {
                string word = q.front();
                q.pop();

                if (word == endWord)
                    return ans;

                dict.erase(word);

                for (int j = 0; j < word.size(); j++)
                {
                    char ch = word[j];
                    for (int k = 0; k < 26; k++)
                    {
                        word[j] = k + 'a';
                        if (dict.find(word) != dict.end())
                        {
                            q.push(word);
                            dict.erase(word);
                        }

                        word[j] = ch;
                    }
                }
            }

            ans++;
        }

        return 0;
    }
};