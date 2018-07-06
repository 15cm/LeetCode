class Solution {
public:
    int maxA(int N) {
      if(N < 4) return N;
      vector<int> dp(N+1);
      iota(dp.begin(), dp.begin() + 4, 0);
      for(int i = 4; i <= N; i++) {
        dp[i] = dp[i-1] + 1;
        for(int j = 4; j < i; j++) {
          dp[i] = max(dp[i], (i - j + 2) * dp[j-3]);
        }
      }
      return dp[N];
    }
};
