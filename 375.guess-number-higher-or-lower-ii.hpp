class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> memo(n, vector<int>(n));
        return dfs(0, n-1, memo);
    }
    int dfs(int lo, int hi, vector<vector<int>>& memo) {
        if(lo == hi) return 0;
        if(lo + 1 == hi) return lo+1;
        if(memo[lo][hi] > 0) return memo[lo][hi];
        int ans = INT_MAX;
        for(int i = lo + 1; i < hi; i++) {
            ans = min(ans, max(dfs(lo, i-1, memo), dfs(i+1, hi, memo)) + i+1);
        }
        return memo[lo][hi] = ans;
    }
};
