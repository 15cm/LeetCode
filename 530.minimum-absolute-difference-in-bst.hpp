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
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        TreeNode *prev = NULL;
        inorder(prev, root, ans);
        return ans;
    }
  void inorder(TreeNode* &prev, TreeNode* node, int& ans) {
        if(!node) return;
        inorder(prev, node->left, ans);
        if(prev) {
          ans = min(ans, abs(node->val - prev->val));
        }
        prev = node;
        inorder(prev, node->right, ans);
    }
};
