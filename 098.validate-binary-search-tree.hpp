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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* x = root;
        int lastVal;
        bool isFirstNode = true;
        while(x != NULL || !s.empty()) {
            while(x != NULL) {
                s.push(x);
                x = x->left;
            }
            auto node = s.top(); s.pop();
            if(isFirstNode) {
                isFirstNode = false;
                lastVal = node->val;
            } else {
                if(node->val <= lastVal) return false;
            }
            lastVal = node->val;
            x = node->right;
        }
        return true;
    }
};
