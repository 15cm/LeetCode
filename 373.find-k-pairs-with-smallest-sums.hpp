class Solution {
    struct Node {
        int a, b, idx;
        Node(int a, int b, int idx): a(a), b(b), idx(idx) {}
        bool operator < (const Node& rhs) const {
            return a + b > rhs.a + rhs.b;
        }
    };
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> ans;
        int n = nums1.size(), m = nums2.size();
        if(n == 0 || m == 0 || k == 0) return ans;
        priority_queue<Node> pq;
        for(int i = 0; i < n && i < k; i++) pq.push(Node(nums1[i], nums2[0], 0));
        while(!pq.empty() && k--) {
            Node node = pq.top(); pq.pop();
            ans.push_back(make_pair(node.a, node.b));
            if(node.idx == m-1) continue;
            pq.push(Node(node.a, nums2[node.idx+1], node.idx+1));
        }
        return ans;
    }
};
