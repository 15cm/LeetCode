class Solution {
public:
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};
    int m, n;
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        m = grid.size(); n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n));
        int cnt = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(!vis[i][j] && grid[i][j] == '1') {
                    dfs(i, j, vis, grid);
                    cnt++;
                }
        return cnt;
    }
    void dfs(int x, int y, vector<vector<bool>>& vis, vector<vector<char>>& grid) {
        vis[x][y] = true;
        for(int i = 0; i < 4; i++) {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if(newx >= 0 && newx < m && newy >= 0 && newy < n) {
                if(!vis[newx][newy] && grid[newx][newy] == '1') dfs(newx, newy, vis, grid);
            }
        }
    }
};
