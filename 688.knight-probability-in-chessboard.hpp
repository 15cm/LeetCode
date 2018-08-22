class Solution {
    vector<vector<int>> dirs {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {1, 2}, {2, 1}, {-1, 2}, {-2, 1}};
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> dp(N, vector<double>(N));
        auto tmp_dp = dp;
        dp[r][c] = 1;
        for(int k = 0; k < K; k++) {
            for(auto &row: tmp_dp) fill(row.begin(), row.end(), 0);
            for(int i = 0; i < N; i++)
                for(int j = 0; j < N; j++)
                    for(auto &dir: dirs) {
                        int x = i + dir[0];
                        int y = j + dir[1];
                        if(is_valid(x, y, N))
                            tmp_dp[x][y] += dp[i][j];
                    }
            dp.swap(tmp_dp);
        }
        double sum = 0;
        for(auto &row: dp)
            for(double v: row)
                sum += v;
        return sum / pow(8, K);
    }
    bool is_valid(int r, int c, int n) {
        return r >= 0 && r < n && c >= 0 && c < n;
    }
};
