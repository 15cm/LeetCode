class Solution {
    vector<int> id;
    vector<int> sz;
    int cnt = 0;
    const int dx[4] = {0,0,1,-1};
    const int dy[4] = {1,-1,0,0};
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        id = vector<int>(m * n, -1);
        sz= vector<int>(m * n, 1);
        int K = positions.size();
        vector<int> ans(K);
        for(int k = 0; k < K; k++) {
            auto& pos = positions[k];
            int idx = pos.first * n + pos.second;
            id[idx] = idx;
            cnt++;
            for(int i = 0; i < 4; i++) {
                int x = pos.first + dx[i];
                int y = pos.second + dy[i];
                if(x >= 0 && x < m && y >= 0 && y < n) {
                    int idx2 = x * n + y;
                    if(id[idx2] != -1)
                        connect(idx, idx2);
                }
            }
            ans[k] = cnt;
        }
        return ans;
    }
    int find(int x) {
        return x == id[x] ? x : id[x] = find(id[x]);
    }
    void connect(int x, int y) {
        int p = find(x);
        int q = find(y);
        if(p == q) return;
        if(sz[p] < sz[q]) {
            id[p] = q;
            sz[q] += sz[p];
        } else {
            id[q] = p;
            sz[p] += sz[q];
        }
        cnt--;
    }
};
