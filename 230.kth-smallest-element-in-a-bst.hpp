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
    int kthSmallest(TreeNode* root, int k) {
        return dfs(root, k);
    }
    int dfs(TreeNode* root, int k) {
        if(!root) return -1;
        int szLeft = treeSize(root->left);
        if(szLeft == k - 1) {
            return root->val;
        } else if(szLeft < k - 1) {
            return dfs(root->right, k - szLeft - 1);
        } else {
            return dfs(root->left, k);
        }
    }
    int treeSize(TreeNode* node) {
        if(!node) return 0;
        return 1 + treeSize(node->left) + treeSize(node->right);
    }
};
