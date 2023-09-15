#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> m;

        Node *ptr = head;
        while (ptr != NULL)
        {
            m[ptr] = new Node(ptr->val);
            ptr = ptr->next;
        }

        ptr = head;
        while (ptr != NULL)
        {
            Node *copy = m[ptr];
            copy->next = m[ptr->next];
            copy->random = m[ptr->random];
            ptr = ptr->next;
        }

        return m[head];
    }
};