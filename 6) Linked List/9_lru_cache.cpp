#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    int value;
    Node *prev;
    Node *next;

    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache
{
public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        left = new Node(-1, -1);
        right = new Node(-1, -1);

        left->next = right;
        right->prev = left;
    }

    int get(int key)
    {
        if (cache.find(key) != cache.end())
        {
            removeNode(cache[key]);
            insertNode(cache[key]);
            return cache[key]->value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            removeNode(cache[key]);

            delete cache[key];
        }

        cache[key] = new Node(key, value);
        insertNode(cache[key]);

        if (cache.size() > capacity)
        {
            Node *LRU = left->next;
            removeNode(LRU);
            cache.erase(LRU->key);
            delete LRU;
        }
    }

private:
    int capacity;
    unordered_map<int, Node *> cache;
    Node *left;
    Node *right;

    void removeNode(Node *node)
    {
        Node *p = node->prev;
        Node *n = node->next;

        p->next = n;
        n->prev = p;
    }

    void insertNode(Node *node)
    {
        Node *p = right->prev;
        Node *n = right;

        p->next = node;
        n->prev = node;

        node->prev = p;
        node->next = n;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */