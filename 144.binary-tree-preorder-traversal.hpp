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
    // Stack
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     stack<TreeNode *> s;
    //     auto cur = root;
    //     while(cur || !s.empty()) {
    //         while(cur) {
    //             ans.push_back(cur->val);
    //             s.push(cur);
    //             cur = cur->left;
    //         }
    //         cur = s.top()->right; s.pop();
    //     }
    //     return ans;
    // }

    // Morris Traversal
    vector<int> preorderTraversal(TreeNode* root) {
        auto cur = root;
        vector<int> ans;
        while(cur) {
            if(!cur->left) {
                ans.push_back(cur->val);
                cur = cur->right;
            } else {
                auto pre = cur->left;
                while(pre->right && pre->right != cur)
                    pre = pre->right;
                if(!pre->right) {
                    ans.push_back(cur->val);
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    pre->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return ans;
    }

};
