/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int order = 0;
    void inorder(TreeNode* root, vector<int>& v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root->val);
        root->val = order++;
        inorder(root->right, v);
    }
    void write(TreeNode* root, vector<int>& v) {
        if (!root) return;
        root->val = v[root->val];
        write(root->left, v);
        write(root->right, v);
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        int size = v.size();
        for (int i = size - 2; i >= 0; --i) {
            v[i] += v[i + 1];
        }
        write(root, v);
        return root;
    }
};