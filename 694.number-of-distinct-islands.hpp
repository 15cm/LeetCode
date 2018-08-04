class Solution {
    int m, n;
    vector<vector<bool>> vis;
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        m = grid.size();
        n = grid[0].size();
        vis = vector<vector<bool>> (m, vector<bool>(n));
        unordered_set<string> ans;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                string shape;
                dfs(i, j, i, j, grid, shape);
                if(!shape.empty())
                    ans.insert(shape);
            }
        return ans.size();
    }
    void dfs(int r, int c, int r0, int c0, vector<vector<int>> &grid, string &shape) {
        if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0 || vis[r][c]) return;
        vis[r][c] = true;
        shape += to_string((r - r0) * 2 * n + (c - c0)) + ",";
        for(int *dir: dirs) {
            dfs(r + dir[0], c + dir[1], r0, c0, grid, shape);
        }
    }
};
