#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;

        Node *ans = new Node(node->val);
        mp[node] = ans;

        queue<Node *> q;
        q.push(node);

        while (!q.empty())
        {
            Node *current = q.front();
            q.pop();

            for (int i = 0; i < current->neighbors.size(); i++)
            {
                Node *neighbor = current->neighbors[i];

                if (mp.find(neighbor) == mp.end())
                {
                    mp[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }

                mp[current]->neighbors.push_back(mp[neighbor]);
            }
        }

        return ans;
    }

private:
    unordered_map<Node *, Node *> mp;
};