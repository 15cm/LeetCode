class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int K = 2, n = prices.size();
        vector<vector<int>> f(K+1, vector<int>(n));
        for(int k = 1; k <= K; k++) {
            int maxj = f[k-1][0] - prices[0];
            for(int i = 1; i < n; i++) {
                f[k][i] = max(f[k][i-1], prices[i] + maxj);
                maxj = max(maxj, f[k-1][i] - prices[i]);
            }
        }
        return f[K][n-1];
    }
};
