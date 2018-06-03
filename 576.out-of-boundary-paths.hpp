#define LL long long
class Solution {
    const vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    const LL M = 1000000007;
public:
    int findPaths(int m, int n, int N, int i, int j) {
        if(m == 0 || n == 0 || N == 0) return 0;
        vector<vector<vector<LL>>> memo(N + 1, vector<vector<LL>>(m, vector<LL>(n, -1)));
        for(int step = 0; step < 2; step++) {
            for(auto &row: memo[step])
                fill(row.begin(), row.end(), 0);
        }
        auto &last = memo[1];
        for(int j = 0; j < n; j++) {
            last[0][j]++;
            last[m-1][j]++;
        }
        for(int i = 0; i < m; i++) {
            last[i][0]++;
            last[i][n-1]++;
        }

        return dfs(i, j, N, memo, m, n);
    }
    int dfs(int r, int c, int step, vector<vector<vector<LL>>> &memo, int m, int n) {
        if(r < 0 || r >= m || c < 0 || c >= n) return 1;
        auto cnt = memo[step][r][c];
        if(cnt != -1) {
            return cnt;
        }
        cnt = 0;
        for(auto &dir: dirs) {
            int x = r + dir.first;
            int y = c + dir.second;
            cnt += dfs(x, y, step - 1, memo, m, n) % M;
        }
        return memo[step][r][c] = cnt % M;
    }
};
