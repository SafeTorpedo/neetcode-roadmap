#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    bool isWord;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
            children[i] = NULL;

        isWord = false;
    }
};

class Solution
{
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        for (string word : words)
            insert(word);

        int m = board.size();
        int n = board[0].size();

        TrieNode *node = root;
        vector<string> ans;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                helper(board, i, j, m, n, node, "", ans);
        }

        return ans;
    }

private:
    TrieNode *root = new TrieNode();

    void insert(string word)
    {
        TrieNode *node = root;
        int temp = 0;

        for (int i = 0; i < word.size(); i++)
        {
            temp = word[i] - 'a';
            if (node->children[temp] == NULL)
                node->children[temp] = new TrieNode();

            node = node->children[temp];
        }

        node->isWord = true;
    }

    void helper(vector<vector<char>> &board, int i, int j, int m, int n, TrieNode *node, string word, vector<string> &ans)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '#')
            return;

        char letter = board[i][j];

        node = node->children[letter - 'a'];
        if (node == NULL)
            return;

        word += board[i][j];
        if (node->isWord)
        {
            ans.push_back(word);
            node->isWord = false;
        }

        board[i][j] = '#';

        helper(board, i - 1, j, m, n, node, word, ans);
        helper(board, i + 1, j, m, n, node, word, ans);
        helper(board, i, j - 1, m, n, node, word, ans);
        helper(board, i, j + 1, m, n, node, word, ans);

        board[i][j] = letter;
    }
};