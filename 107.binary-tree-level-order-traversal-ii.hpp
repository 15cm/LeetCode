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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        list<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> vec;
            int n = q.size();
            while(n--) {
                auto x = q.front(); q.pop();
                if(x) {
                    vec.push_back(x->val);
                    q.push(x->left);
                    q.push(x->right);
                }
            }
            if(!vec.empty()) ans.push_front(vec);
        }
        return vector<vector<int>> (ans.begin(), ans.end());
    }
};
