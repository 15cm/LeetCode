/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1) {
            auto node = new TreeNode(v);
            node->left = root;
            return node;
        }
        dfs(root, v, d);
        return root;
    }
    void dfs(TreeNode* node, int v, int d) {
        if(!node) return;
        if(d == 2) {
            auto left = node->left;
            auto right = node->right;
            node->left = new TreeNode(v);
            node->left->left = left;
            node->right = new TreeNode(v);
            node->right->right = right;
            return;
        }
        dfs(node->left, v, d - 1);
        dfs(node->right, v, d - 1);
    }
};
