struct Node {
    int r,c, val;
    Node() {}
    Node(int r, int c, int val): r(r), c(c), val(val) {}
    bool operator < (const Node &node) const {
        return val > node.val;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int m = nums.size();
        priority_queue<Node> pq;
        int lo = 0, hi = INT_MAX;
        int maxv = INT_MIN;
        for(int i = 0; i < m; i++) {
            pq.push(Node(i, 0, nums[i][0]));
            maxv = max(maxv, nums[i][0]);
        }
        if(maxv - pq.top().val < hi - lo) {
            lo = pq.top().val;
            hi = maxv;
        }
        while(true) {
            auto &node = pq.top();
            int nextCol = node.c + 1;
            if(nextCol == nums[node.r].size()) break;
            Node nextNode(node.r, nextCol, nums[node.r][nextCol]);
            pq.pop();
            pq.push(nextNode);
            maxv = max(maxv, nextNode.val);
            if(maxv - pq.top().val < hi - lo) {
                lo = pq.top().val;
                hi = maxv;
            }
        }
        return {lo, hi};
    }
};
