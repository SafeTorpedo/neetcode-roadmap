#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        if (root == NULL)
            return {};

        vector<int> ans;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int ctr = q.size();

            for (int i = 0; i < ctr; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if (i == ctr - 1)
                    ans.push_back(node->val);

                if (node->left != NULL)
                    q.push(node->left);

                if (node->right != NULL)
                    q.push(node->right);
            }
        }

        return ans;
    }
};