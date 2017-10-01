class Solution {
public:
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    grid[i][j] = '0';
                    dfs(i, j, grid);
                    cnt++;
                }
            }
        return cnt;
    }
    void dfs(int x, int y, vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < 4; i++) {
            int x2 = x + dx[i];
            int y2 = y + dy[i];
            if(x2 >= 0 && x2 < m && y2 >= 0 && y2 < n) {
                if(grid[x2][y2] == '1') {
                    grid[x2][y2] = '0';
                    dfs(x2, y2, grid);
                }
            }
        }
    }
};
