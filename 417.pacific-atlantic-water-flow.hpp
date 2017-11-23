class Solution {
    const int dx[4] = {0,0,1,-1};
    const int dy[4] = {1,-1,0,0};
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> ans;
        if(matrix.empty() || matrix[0].empty()) return ans;
        int m = matrix.size(), n = matrix[0].size();

        vector<vector<bool>> vis1(m, vector<bool>(n)), vis2(m, vector<bool>(n));

        for(int i = 0; i < m; i++) {
            dfs(i, 0, vis1, matrix);
            dfs(i, n-1, vis2, matrix);
        }
        for(int i = 0; i < n; i++) {
            dfs(0, i, vis1, matrix);
            dfs(m-1, i, vis2, matrix);
        }

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                if(vis1[i][j] && vis2[i][j])
                    ans.push_back(make_pair(i, j));
            }
        return ans;
    }
    void dfs(int r, int c, vector<vector<bool>>& vis, vector<vector<int>>& matrix) {
        vis[r][c] = true;
        int m = matrix.size(), n = matrix[0].size();

        for(int i = 0; i < 4; i++) {
            int x = r + dx[i];
            int y = c + dy[i];
            if(x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && matrix[x][y] >= matrix[r][c]) {
                dfs(x, y, vis, matrix);
            }
        }
    }
};
