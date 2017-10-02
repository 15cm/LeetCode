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
    TN* prev = NULL;
public:
    bool isValidBST(TreeNode* root) {
        stack<TN*> s;
        while(root || !s.empty()) {
            while(root) {
                s.push(root);
                root = root->left;
            }
            root = s.top(); s.pop();
            if(prev && root->val <= prev->val) return false;
            prev = root;
            root = root->right;
        }
        return true;
    }
};
