class Solution {
    vector<int> id;
    vector<int> sz;
    int cnt;
public:
    int findCircleNum(vector<vector<int>>& M) {
        if(M.empty() || M[0].empty()) return 0;
        int n = M.size();
        id = vector<int>(n);
        sz = vector<int>(n, 1);
        iota(id.begin(), id.end(), 0);
        cnt = n;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(M[i][j]) {
                    connect(i, j);
                }
            }
        }
        return cnt;
    }
    int find(int x) {
        return (id[x] == x ? x : (id[x] = find(id[x])));
    }
    void connect(int x, int y) {
        int p = find(x), q = find(y);
        if(p == q) return;
        cnt--;
        if(sz[p] > sz[q]) {
            swap(p, q);
        }
        id[p] = q;
        sz[q] += sz[p];
    }
};
