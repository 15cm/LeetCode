class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size();
        int k = days[0].size();
        vector<vector<int>> f(n, vector<int>(k, -1));
        return dfs(0, 0, f, flights, days);
    }
    int dfs(int u, int w, vector<vector<int>>& f, vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size();
        int k = days[0].size();
        if(w == k) return 0;
        if(f[u][w] != -1) return f[u][w];

        int res = 0;
        for(int v = 0; v < n; v++) {
            if(flights[u][v] || u == v) {
                res = max(res, days[v][w] + dfs(v, w + 1, f, flights, days));
            }
        }
        return f[u][w] = res;
    }
};
