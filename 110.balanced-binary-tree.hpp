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
    bool isBalanced(TreeNode* root) {
        return getDepth(root) != -1;
    }
    int getDepth(TreeNode* root) {
        if(!root) return 0;
        int depthLeft = getDepth(root->left);
        if(depthLeft == -1) return -1;
        int depthRight = getDepth(root->right);
        if(depthRight == -1) return -1;
        if(abs(depthLeft - depthRight) > 1) return -1;
        return max(depthLeft, depthRight) + 1;
    }
};
