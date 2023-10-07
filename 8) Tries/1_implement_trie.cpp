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

class Trie
{
public:
    Trie()
    {
        root = new TrieNode();
    }

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

    bool search(string word)
    {
        TrieNode *node = root;
        int temp = 0;

        for (int i = 0; i < word.size(); i++)
        {
            temp = word[i] - 'a';
            if (node->children[temp] == NULL)
                return false;

            node = node->children[temp];
        }

        return node->isWord;
    }

    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        int temp = 0;

        for (int i = 0; i < prefix.size(); i++)
        {
            temp = prefix[i] - 'a';
            if (node->children[temp] == NULL)
                return false;

            node = node->children[temp];
        }

        return true;
    }

private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */