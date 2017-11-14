class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> id(n+1);
        vector<int> candA, candB;
        for(auto& edge: edges) {
            int u = edge[0], v = edge[1];
            if(id[v] == 0) {
                id[v] = u;
            } else {
                candA = vector<int> {id[v], v};
                candB = edge;
                edge[1] = 0;
            }
        }
        for(int i = 1; i <= n; i++) id[i] = i;
        for(auto& edge: edges) {
            if(edge[1] == 0) continue;
            int u = edge[0], v = edge[1];
            int pu = ufind(u, id);
            if(pu == v) {
                if(candA.empty()) return edge;
                return candA;
            }
            id[v] = pu;
        }
        return candB;
    }
private:
    int ufind(int x, vector<int>& id) {
        return x == id[x] ? x : id[x] = ufind(id[x], id);
    }
};
