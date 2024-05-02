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
    bool findTarget(TreeNode* root, int k) {
        queue<TreeNode*> q;
        unordered_map<int, int> m;
        q.push(root);
        while (!q.empty()) {
            TreeNode* f = q.front();
            q.pop();
            m[f->val]++;
            if (f->left) q.push(f->left);
            if (f->right) q.push(f->right);
        }
        for (auto& pair : m) {
            if (k % 2 == 0 && pair.first == k / 2) continue; 
            if (m.find(k - pair.first) != m.end()) return true;
        }
        return false;
    }
};