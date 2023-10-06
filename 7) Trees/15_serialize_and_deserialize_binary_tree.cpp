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

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        ostringstream ans;
        encode(root, ans);
        return ans.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        istringstream input(data);
        return decode(input);
    }

private:
    void encode(TreeNode *root, ostringstream &ans)
    {
        if (root == NULL)
        {
            ans << "N ";
            return;
        }

        ans << root->val << " ";
        encode(root->left, ans);
        encode(root->right, ans);
    }

    TreeNode *decode(istringstream &input)
    {
        string value = "";
        input >> value;

        if (value == "N")
            return NULL;

        TreeNode *root = new TreeNode(stoi(value));
        root->left = decode(input);
        root->right = decode(input);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));