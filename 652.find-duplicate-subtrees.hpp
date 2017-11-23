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
    unordered_map<string, int> cache;
    vector<TreeNode*> ans;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        return ans;
    }
    string serialize(TreeNode* node) {
        if(!node) return "#";
        string left = serialize(node->left);
        string right = serialize(node->right);
        string res = to_string(node->val) + "," + left + "," + right;
        cache[res]++;
        if(cache[res] == 2) {
            ans.push_back(node);
        }
        return res;
    }
};
