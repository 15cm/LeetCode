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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        stack<int> s1, s2;
        inorder(root, target, s1, false);
        inorder(root, target, s2, true);

        vector<int> ans(k);
        for(int i = 0; i < k; i++) {
            if(s1.empty()) { ans[i] = s2.top(); s2.pop(); }
            else if(s2.empty()) { ans[i] = s1.top(); s1.pop(); }
            else {
                double d1 = abs(s1.top() - target), d2 = abs(s2.top() - target);
                if(d1 < d2) { ans[i] = s1.top(); s1.pop(); }
                else { ans[i] = s2.top(); s2.pop(); }
            }
        }
        return ans;
    }
    void inorder(TreeNode* node, double target, stack<int>& s, bool isReversed) {
        if(!node) return;
        inorder(isReversed ? node->right : node->left, target, s, isReversed);
        if((isReversed && node->val <= target) || (!isReversed && node->val > target))
            return;
        s.push(node->val);
        inorder(isReversed ? node->left : node->right, target, s, isReversed);
    }
};
