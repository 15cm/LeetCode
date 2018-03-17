struct Node {
    int r, c, val;
    Node(int r, int c, int val): r(r), c(c), val(val) {}

    bool operator < (const Node& p) const {
        return val > p.val;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<Node> pq;
        for(int i = 0; i < n; i++) pq.push(Node(0, i, matrix[0][i]));
        for(int i = 0; i < k-1; i++) {
            auto p = pq.top();
            pq.pop();
            if(p.r == n-1) continue;
            int r = p.r + 1, c = p.c;
            pq.push(Node(r, c, matrix[r][c]));
        }
        return pq.top().val;
    }
};
