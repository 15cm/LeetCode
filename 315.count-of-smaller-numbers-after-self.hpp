class Solution {
public:
    struct Node {
        int val, smaller;
        Node *left = NULL, *right = NULL;
        Node(int val, int smaller): val(val), smaller(smaller) {}
    };
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        Node* root = NULL;
        for(int i = n-1; i >= 0; i--) {
            int cnt = 0;
            root = insert(root, nums[i], cnt);
            ans[i] = cnt;
        }
        return ans;
    }

    Node* insert(Node* root, int val, int& cnt) {
        if(!root) return new Node(val, 0);
        if(val < root->val) {
            root->smaller++;
            root->left = insert(root->left, val, cnt);
        } else {
            cnt += root->smaller + (val > root->val);
            root->right = insert(root->right, val, cnt);
        }
        return root;
    }
};
