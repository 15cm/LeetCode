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
    vector<int> findMode(TreeNode* root) {
        if(!root) return {};
        int prev, cnt = 0, maxCnt = 0;
        vector<int> ans;
        inorder(root, prev, cnt, maxCnt, ans);
        if(cnt >= maxCnt) {
            if(cnt > maxCnt) {
                maxCnt = cnt;
                ans.clear();
            }
            ans.push_back(prev);
        }
        return ans;
    }
    void inorder(TreeNode *node, int& prev, int& cnt, int& maxCnt, vector<int>& ans) {
        if(!node) return;
        inorder(node->left, prev, cnt, maxCnt, ans);
        if(cnt > 0) {
            if(node->val == prev) {
                cnt++;
            } else {
                if(cnt >= maxCnt) {
                    if(cnt > maxCnt) {
                        maxCnt = cnt;
                        ans.clear();
                    }
                    ans.push_back(prev);
                }
                cnt = 1;
            }
        } else {
            cnt++;
        }
        prev = node->val;
        inorder(node->right, prev, cnt, maxCnt, ans);
    }
};
