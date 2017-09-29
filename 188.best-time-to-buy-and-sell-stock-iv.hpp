class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int K = k, n = prices.size();
        if(n < 2) return 0;
        if(K >= n/2) {
            int ans = 0, lo = 0;
            for(int i = 1; i < n; i++) {
                if(prices[i] < prices[i-1]) {
                    ans += prices[i-1] - prices[lo];
                    lo = i;
                }
            }
            ans += max(0, prices.back() - prices[lo]);
            return ans;
        } else {
            vector<vector<int>> f(K+1, vector<int>(n));
            for(int k = 1; k <= K; k++) {
                int maxp = -prices[0];
                for(int i = 1; i < n; i++) {
                    f[k][i] = max(f[k][i-1], prices[i] + maxp);
                    maxp = max(maxp, f[k-1][i] - prices[i]);
                }
            }
            return f[K][n-1];
        }
    }
};
