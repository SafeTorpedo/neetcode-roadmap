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

class WordDictionary
{
public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(string word)
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

    bool search(string word)
    {
        TrieNode *node = root;
        return helper(word, 0, node);
    }

private:
    TrieNode *root;

    bool helper(string &word, int i, TrieNode *node)
    {
        if (node == NULL)
            return false;

        if (i == word.size())
            return node->isWord;

        if (word[i] != '.')
            return helper(word, i + 1, node->children[word[i] - 'a']);

        for (int j = 0; j < 26; j++)
        {
            if (helper(word, i + 1, node->children[j]))
                return true;
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */