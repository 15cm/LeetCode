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
    int pathSum(TreeNode* root, int sum) {
        int ans = 0;
        dfs(root, sum, ans);
        return ans;
    }
    unordered_multiset<int> dfs(TreeNode* node, int target, int& ans) {
        unordered_multiset<int> res;
        if(!node) return res;
        int val = node->val;
        auto left = dfs(node->left, target, ans);
        auto right = dfs(node->right, target, ans);
        for(auto x: left) {
            res.insert(val + x);
        }
        for(auto x: right) {
            res.insert(val + x);
        }
        res.insert(val);
        ans += res.count(target);
        return res;
    }
};
