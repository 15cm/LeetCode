/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef TreeNode TN;
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream os;
        serialize(root, os);
        return os.str();
    }

    void serialize(TN* root, ostringstream& os) {
        if(!root) return;
        os << root->val << " ";
        serialize(root->left, os);
        serialize(root->right, os);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        vector<int> arr;
        int t;
        while(is >> t) {
            arr.push_back(t);
        }
        return deserialize(0, arr.size() - 1, arr);
    }

    TreeNode* deserialize(int lo, int hi, vector<int>& data) {
        if(lo > hi) return NULL;
        TN* root = new TN(data[lo]);
        int left = lo + 1;
        int right = left;
        for(; right <= hi && data[right] < data[lo]; right++);
        root->left = deserialize(left, right - 1, data);
        root->right = deserialize(right, hi, data);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
