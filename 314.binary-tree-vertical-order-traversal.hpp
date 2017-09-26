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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        unordered_map<int, list<int>> mp;
        int lo = 0, hi = 0;
        vector<vector<int>> ans;
        queue<pair<TreeNode*, int>> q;
        if(!root) return ans;
        q.push(make_pair(root, 0));
        int levelSize = 1;
        while(!q.empty()) {
            int sz = 0;
            for(int i = 0; i < levelSize; i++) {
                auto x = q.front(); q.pop();
                auto u = x.first;
                int col = x.second;
                if(!mp.count(col)) mp[col] = list<int>();
                mp[col].push_back(u->val);
                if(u->left) {
                    lo = min(lo, col - 1);
                    q.push(make_pair(u->left, col - 1));
                    sz++;
                }
                if(u->right) {
                    hi = max(hi, col + 1);
                    q.push(make_pair(u->right, col + 1));
                    sz++;
                }
            }
            levelSize = sz;
        }

        for(int i = lo; i <= hi; i++) {
            ans.push_back(vector<int>(mp[i].begin(), mp[i].end()));
        }
        return ans;
    }
};
