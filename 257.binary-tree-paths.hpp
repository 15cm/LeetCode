/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef TreeNode Node;
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        list<int> path;
        dfs(root, path, ans);
        return ans;
    }
    void dfs(Node* node, list<int>& path, vector<string>& ans) {
        if(!node) return;
        if(!node->left && !node->right) {
            string s;
            for(int e: path) {
                s += to_string(e) + "->";
            }
            s += to_string(node->val);
            ans.push_back(s);
            return;
        }
        path.push_back(node->val);
        dfs(node->left, path, ans);
        dfs(node->right, path, ans);
        path.pop_back();
    }
};
