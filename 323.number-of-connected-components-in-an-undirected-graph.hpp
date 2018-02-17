class Solution {
    vector<int> id, sz;
    int cnt;
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        id = vector<int>(n);
        sz = vector<int>(n, 1);
        for(int i = 0; i < n; i++) id[i] = i;
        cnt = n;
        for(auto& pr: edges) {
            connect(pr.first, pr.second);
        }
        return cnt;
    }
    int find(int x) {
        return id[x] == x ? x : (id[x] = find(id[x]));
    }
    void connect(int x, int y) {
        int p = find(x), q = find(y);
        if(p != q) {
            if(sz[p] < sz[q]) {
                id[p] = q;
                sz[q] += sz[p];
            } else {
                id[q] = p;
                sz[p] += sz[q];
            }
            cnt--;
        }
    }
};
