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
    bool postorder(TreeNode* node, int &target) {
        if (node->left) if(postorder(node->left, target)) node->left = nullptr;
        if (node->right) if(postorder(node->right, target)) node->right = nullptr;
        if (!node->left && !node->right) return node->val == target;
        return false;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int &target) {
        if (postorder(root, target)) return nullptr;
        else return root;
    }
};