class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m = ring.size(), n = key.size();
        if(!m || !n) return 0;
        vector<vector<int>> mp(26);
        for(int i = 0; i < m;i ++)
            mp[ring[i] - 'a'].push_back(i);

        vector<int> dp(m);
        vector<int> start(1);
        auto prev = &start;

        for(int i = 0; i < n; i++) {
            vector<int> nextDp(m, INT_MAX);
            for(int j: mp[key[i] - 'a']) {
                for(int k: *prev) {
                    int minDist = min((j - k + m) % m, (k - j + m) % m) + dp[k];
                    nextDp[j] = min(nextDp[j], minDist);
                }
            }
            dp = nextDp;
            prev = &mp[key[i] - 'a'];
        }
        return *min_element(dp.begin(), dp.end()) + n;
    }
};
