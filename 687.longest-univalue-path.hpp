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
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
    int dfs(TreeNode* node, int& ans) {
        if(!node) return 0;
        int left = dfs(node->left, ans);
        int right = dfs(node->right, ans);
        if(node->left) {
            if(node->val == node->left->val)
                left++;
            else
                left = 0;
        }
        if(node->right) {
            if(node->val == node->right->val)
                right++;
            else
                right = 0;
        }
        ans = max(ans, left + right);
        return max(left, right);
    }
};
