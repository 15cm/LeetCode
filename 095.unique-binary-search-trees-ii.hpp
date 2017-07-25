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
    struct pairHash {
        template<typename A, typename B>
        size_t operator ()(const pair<A, B>& x) const {
            return hash<A>()(x.first) ^ hash<B>()(x.second);
        }
    };
    vector<TreeNode*> generateTrees(int n) {
        unordered_map<pair<int, int>, vector<TreeNode*>*, pairHash> mp;
        return n == 0 ? vector<TreeNode*> {} : *genNodes(1, n, mp);
    }
    vector<TreeNode*>* genNodes(int start, int end, unordered_map<pair<int, int>, vector<TreeNode*>*, pairHash>& mp) {
        vector<TreeNode*>* nodes = new vector<TreeNode*>;
        if(start > end) {
            nodes->push_back(NULL);
            return nodes;
        }
        if(start == end) {
            nodes->push_back(new TreeNode(start));
            return nodes;
        }
        for(int i = start; i <= end; i++) {
            auto leftRegion = make_pair(start, i - 1), rightRegion = make_pair(i + 1, end);
            auto leftNodes = mp.find(leftRegion) == mp.end() ? genNodes(start, i - 1, mp)
                : mp[leftRegion];
            auto rightNodes = mp.find(rightRegion) == mp.end() ? genNodes(i + 1, end, mp)
                : mp[rightRegion];
            for(auto& lNode: *leftNodes)
                for(auto& rNode: *rightNodes) {
                    TreeNode* root = new TreeNode(i);
                    root->left = lNode;
                    root->right = rNode;
                    nodes->push_back(root);
                }
        }
        return nodes;
    }
};
