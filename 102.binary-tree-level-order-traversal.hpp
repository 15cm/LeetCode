#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            queue<TreeNode*> q0;
            vector<int> vec;
            while(!q.empty()) {
                auto x = q.front(); q.pop();
                if(x) {
                    vec.push_back(x->val);
                    q0.push(x->left);
                    q0.push(x->right);
                }
            }
            if(!vec.empty())ans.push_back(vec);
            q0.swap(q);
        }
        return ans;
    }
};
