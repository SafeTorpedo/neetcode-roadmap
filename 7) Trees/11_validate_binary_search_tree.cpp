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
    bool isValidBST(TreeNode *root)
    {
        vector<int> arr;
        bool ans = true;
        inorder(root, arr, ans);
        return ans;
    }

private:
    void inorder(TreeNode *root, vector<int> &arr, bool &ans)
    {
        if (root == NULL || !ans)
            return;

        inorder(root->left, arr, ans);

        if (!arr.empty() && arr.back() >= root->val)
            ans = false;
        else
            arr.push_back(root->val);

        inorder(root->right, arr, ans);
    }
};