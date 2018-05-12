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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(!root) return {};
        unordered_map<int, int> mp;
        int maxCnt = 0;
        dfs(root, mp, maxCnt);
        vector<int> ans;
        for(auto &pr: mp) {
            if(pr.second == maxCnt)
                ans.push_back(pr.first);
        }
        return ans;
    }
    int dfs(TreeNode* node, unordered_map<int, int> &mp, int &maxCnt) {
        if(!node) return 0;
        int sum = dfs(node->left, mp, maxCnt) + dfs(node->right, mp, maxCnt) + node->val;
        maxCnt = max(maxCnt, mp[sum]);
        return sum;
    }
};
