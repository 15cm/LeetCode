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
    vector<string> binaryTreePaths(TreeNode* root) {
        list<list<int>> paths;
        vector<string> ans;
        if(!root) return ans;
        list<int> path;
        buildPath(root, path, paths);
        for(auto& path: paths) {
            string s;
            auto it = path.begin();
            s += to_string(*(it++));
            while(it != path.end()) {
                s += "->" + to_string(*(it++));
            }
            ans.push_back(s);
        }
        return ans;
    }
    void buildPath(TreeNode *root, list<int> &path, list<list<int>> &paths) {
        if(!root->left && !root->right) {
            list<int> t(path);
            t.push_back(root->val);
            paths.push_back(t);
        }
        path.push_back(root->val);
        if(root->left) buildPath(root->left, path, paths);
        if(root->right) buildPath(root->right, path, paths);
        path.pop_back();
    }
};
