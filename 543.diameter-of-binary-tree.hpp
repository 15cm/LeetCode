/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef TreeNode TN;
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        maxHeight(root, ans);
        return ans;
    }

    int maxHeight(TN *root, int& ans) {
        if(!root) return 0;
        int left = maxHeight(root->left, ans);
        int right = maxHeight(root->right, ans);
        ans = max(ans, left + right);
        return max(left, right) + 1;
    }
};
