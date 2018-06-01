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
    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
    pair<int, int> dfs(TreeNode *node, int &ans) {
        int incLen, decLen;
        incLen = decLen = 1;
        if(node->left) {
            auto leftRes = dfs(node->left, ans);
            if(node->val + 1== node->left->val) {
                incLen += leftRes.first;
            } else if(node->val - 1 == node->left->val) {
                decLen += leftRes.second;
            }
        }
        if(node->right) {
            auto rightRes = dfs(node->right, ans);
            if(node->val + 1 == node->right->val) {
                incLen = max(incLen, rightRes.first + 1);
            } else if(node->val - 1 == node->right->val) {
                decLen = max(decLen, rightRes.second + 1);
            }
        }
        ans = max(ans, incLen + decLen - 1);
        return {incLen, decLen};
    }
};
