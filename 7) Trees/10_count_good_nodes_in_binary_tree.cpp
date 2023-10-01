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
    int goodNodes(TreeNode *root)
    {
        int ans = 0;
        dfs(root, root->val, ans);
        return ans;
    }

private:
    void dfs(TreeNode *root, int tempMax, int &ans)
    {
        if (root == NULL)
            return;

        if (root->val >= tempMax)
            ans++;

        dfs(root->left, max(tempMax, root->val), ans);
        dfs(root->right, max(tempMax, root->val), ans);
    }
};