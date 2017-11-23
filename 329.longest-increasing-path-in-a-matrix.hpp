class Solution {
    const int dx[4] = {0,0,1,-1};
    const int dy[4] = {1,-1,0,0};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        vector<vector<int>> memo(m, vector<int>(n));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                ans = max(ans, 1 + dfs(i, j, memo, matrix));
            }
        return ans;
    }

    int dfs(int r, int c, vector<vector<int>>& memo, vector<vector<int>>& matrix) {
        if(memo[r][c]) return memo[r][c];

        int m = matrix.size(), n = matrix[0].size();
        int res = 0;
        for(int i = 0; i < 4; i++) {
            int x = r + dx[i];
            int y = c + dy[i];
            if(x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[r][c]) {
                res = max(res, 1 + dfs(x, y, memo, matrix));
            }
        }
        return memo[r][c] = res;
    }
};
