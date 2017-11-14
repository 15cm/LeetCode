class Solution {
    vector<int> id;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = 0;
        for(auto& edge: edges)
            for(int u: edge)
                N = max(u, N);
        id = vector<int>(N+1);
        for(int i = 1; i <= N; i++) id[i] = i;
        for(auto& edge: edges) {
            int u = edge[0], v = edge[1];
            if(isConnected(u, v))
                return vector<int> {u, v};
            connect(u, v);
        }
        return vector<int>();
    }
    int ufind(int x) {
        return id[x] == x ? x : id[x] = ufind(id[x]);
    }
    bool isConnected(int x, int y) {
        return ufind(x) == ufind(y);
    }
    void connect(int x, int y) {
        int p = ufind(x), q = ufind(y);
        if(p != q) {
            id[p] = q;
        }
    }
};
