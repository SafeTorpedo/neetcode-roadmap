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
    bool isBalanced(TreeNode *root)
    {
        bool ans = true;
        helper(root, ans);
        return ans;
    }

private:
    int helper(TreeNode *root, bool &ans)
    {
        if (root == NULL)
            return 0;

        int leftHeight = helper(root->left, ans);
        int rightHeight = helper(root->right, ans);

        if (abs(leftHeight - rightHeight) > 1)
            ans = false;

        return 1 + max(leftHeight, rightHeight);
    }
};