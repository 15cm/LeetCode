class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        vector<int> dp(k+1);
        int n = Profits.size();
        vector<int> index(n);
        iota(index.begin(), index.end(), 0);
        if(!is_sorted(Capital.begin(), Capital.end())) {
            sort(index.begin(), index.end(), [&Capital](auto i1, auto i2) {
                    return Capital[i1] < Capital[i2];
                });
        }
        if(k >= n) {
            dp[0] = W;
            for(int i = 1; i <= n; i++) {
                int idx = index[i-1];
                dp[i] = dp[i-1] + (dp[i-1] >= Capital[idx] ? Profits[idx] : 0);
            }
            return dp[n];
        } else {
            fill(dp.begin(), dp.end(), W);
            for(int i = 1; i <= n; i++) {
                int idx = index[i-1];
                for(int v = k; v >= 1; v--) {
                    dp[v] = max(dp[v], dp[v-1] >= Capital[idx] ? dp[v-1] + Profits[idx] : 0);
                }
            }
            return dp[k];
        }
    }
};
