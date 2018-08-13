class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        if(days.empty() || days[0].empty()) return 0;
        int N = days.size(), K = days[0].size();
        vector<vector<int>> dp(N, vector<int>(K + 1, -1));
        dp[0][0] = 0;
        for(int j = 1; j <= K; j++)
            for(int i = 0; i < N; i++) {
                dp[i][j] = dp[i][j-1];
                for(int k = 0; k < N; k++) {
                    if(flights[k][i]) {
                        dp[i][j] = max(dp[i][j], dp[k][j-1]);
                    }
                }
                if(dp[i][j] >= 0) dp[i][j] += days[i][j-1];
            }
        int ans = 0;
        for(int i = 0; i < N; i++)
            ans = max(ans, dp[i][K]);
        return ans;
    }
};
