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
    vector<int> inorderTraversal(TreeNode* root) {
        list<int> ans;
        while(root) {
            if(root->left) {
                TreeNode *x = root->left;
                while(x->right && x->right != root) x = x->right;
                if(x->right == root) {
                    x->right = NULL;
                    ans.push_back(root->val);
                    root = root->right;
                }
                else {
                    x->right = root;
                    root = root->left;
                }
            } else {
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return vector<int>(ans.begin(), ans.end());
    }
};
