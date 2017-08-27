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
    int maxPathSum(TreeNode* root) {
        int ans = numeric_limits<int>::min();
        maxSum(root, ans);
        return ans;
    }
    int maxSum(TreeNode* x, int& ans) {
        if(x) {
            int sum = x->val, maxLeft = max(maxSum(x->left, ans), 0), maxRight = max(maxSum(x->right, ans), 0);
            sum += maxLeft + maxRight;
            if(sum > ans) ans = sum;
            return x->val + max(maxLeft, maxRight);
        } else {
            return 0;
        }
    }
}; 
