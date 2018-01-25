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
    int countUnivalSubtrees(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
    bool dfs(TreeNode* node, int &cnt) {
        int v = node->val;
        bool left = !node->left || dfs(node->left, cnt) && v == node->left->val;
        bool right = !node->right || dfs(node->right, cnt) && v == node->right->val;
        if(left && right) {
            cnt++;
            return true;
        }
        return false;
    }
};
