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
    void inorder(TreeNode* root, vector<int>& v) {
        if (!root) {
            return;
        }
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    void build(TreeNode* node, vector<int>& v, int left, int right) {
        int mid = (left + right) / 2;
        if (left == right) {
            node->val = v[mid];
        }
        else if (mid == left) {
            node->val = v[mid];
            node->right = new TreeNode(v[right]);
        } else {
            node->val = v[mid];
            TreeNode* l = new TreeNode;
            TreeNode* r = new TreeNode;
            node->left = l;
            node->right = r;
            build(l, v, left, mid - 1);
            build(r, v, mid + 1, right);
        }
    }
    TreeNode* balanceBST(TreeNode* root) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int> v;
        inorder(root, v);
        TreeNode* node = new TreeNode;
        build(node, v, 0, v.size() - 1);
        return node;
    }
};