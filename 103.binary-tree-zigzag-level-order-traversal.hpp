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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        stack<TreeNode*> s;
        bool isZig = true;
        s.push(root);
        while(!s.empty()) {
            vector<int> vec;
            stack<TreeNode*> s0;
            while(!s.empty()) {
                auto x = s.top(); s.pop();
                if(x) {
                    if(isZig) {
                        s0.push(x->left);
                        s0.push(x->right);
                    } else {
                        s0.push(x->right);
                        s0.push(x->left);
                    }
                    vec.push_back(x->val);
                }
            }
            isZig = !isZig;
            s.swap(s0);
            if(!vec.empty()) ans.push_back(vec);
        }
        return ans;
    }
};
