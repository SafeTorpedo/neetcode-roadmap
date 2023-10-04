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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> m;
        int n = inorder.size();

        for (int i = 0; i < n; i++)
            m[inorder[i]] = i;

        TreeNode *root = helper(preorder, 0, n - 1, inorder, 0, n - 1, m);
        return root;
    }

private:
    TreeNode *helper(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &m)
    {
        if (preStart > preEnd || inStart > inEnd)
            return NULL;

        TreeNode *root = new TreeNode(preorder[preStart]);

        int inRoot = m[root->val];
        int left = inRoot - inStart;

        root->left = helper(preorder, preStart + 1, preStart + left, inorder, inStart, inRoot - 1, m);
        root->right = helper(preorder, preStart + left + 1, preEnd, inorder, inRoot + 1, inEnd, m);

        return root;
    }
};