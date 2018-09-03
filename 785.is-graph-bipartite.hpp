class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);
        for(int i = 0; i < n; i++)
            if(colors[i] == -1 && fail(i, 0, colors, graph))
                return false;
        return true;
    }
    bool fail(int id, int c, vector<int> &colors, vector<vector<int>> &graph) {
        colors[id] = c;
        for(int nb: graph[id]) {
            if(colors[nb] == c) return true;
            if(colors[nb] == -1 && fail(nb, c ^ 1, colors, graph)) {
                return true;
            }
        }
        return false;
    }
};
