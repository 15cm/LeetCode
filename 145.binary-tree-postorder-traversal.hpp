/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define MAX_SIZE 65536
class Solution {
public:
    // Stack
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<bool> vis(MAX_SIZE);
    //     stack<TreeNode *> s;
    //     vector<int> ans;
    //     auto x = root;

    //     while(x) {
    //         s.push(x);
    //         int n = s.size();
    //         if(n > vis.size()) vis.resize(n);
    //         x = x->left;
    //     }

    //     while(!s.empty()) {
    //         x = s.top();
    //         while(x->right && !vis[s.size()]) {
    //             x = x->right;
    //             vis[s.size()] = true;
    //             while(x) {
    //                 s.push(x);
    //                 int n = s.size();
    //                 if(n > vis.size()) vis.resize(n);
    //                 vis[n] = false;
    //                 x = x->left;
    //             }
    //             x = s.top();
    //         }
    //         s.pop();
    //         ans.push_back(x->val);
    //     }

    //     return ans;
    // }

    // Morris Traversal
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode dummy(-1);
        dummy.left = root;
        auto cur = &dummy;
        while(cur) {
            if(!cur->left) cur = cur->right;
            else {
                auto pre = cur->left;
                while(pre->right && pre->right != cur)
                    pre = pre->right;
                if(!pre->right) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    pre->right = NULL;
                    traverse_right_path_reverse(cur->left, ans);
                    cur = cur->right;
                }
            }
        }
        return ans;
    }
    void traverse_right_path_reverse(TreeNode *root, vector<int> &vec) {
        list<int> l;
        for(auto x = root; x != NULL; x = x->right)
            l.push_front(x->val);
        vec.insert(vec.end(), l.begin(), l.end());
    }
};
