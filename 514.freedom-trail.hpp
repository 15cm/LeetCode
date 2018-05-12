class Solution {
public:
    int findRotateSteps(string ring, string key) {
        vector<vector<int>> mp(26);
        int m = ring.size(), n = key.size();
        if(m == 0 || n == 0) return 0;
        for(int i = 0; i < m; i++)
            mp[ring[i] - 'a'].push_back(i);
        vector<vector<int>> dp(n+1, vector<int>(m, INT_MAX));
        fill(dp[0].begin(), dp[0].end(), 0);
        auto tmp = vector<int>(1);
        auto prev = &tmp;
        for(int i = 1; i <= n; i++) {
            for(int j: mp[key[i-1] - 'a']) {
                for(int k: *prev) {
                    int minDist = min((j - k + m) % m, (k - j + m) % m) + dp[i-1][k];
                    dp[i][j] = min(dp[i][j], minDist);
                }
            }
            prev = &mp[key[i-1] - 'a'];
        }
        return *min_element(dp[n].begin(), dp[n].end()) + n;
    }
};
