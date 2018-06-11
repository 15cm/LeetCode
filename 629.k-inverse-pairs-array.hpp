class Solution {
    const int M = 1000000007;
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> f(k + 1, vector<int>(n + 1));
        fill(f[0].begin(), f[0].end(), 1);
        f[0][0] = 0;
        for(int j = 1; j <= n; j++) {
            long sum = 0;
            for(int i = k;  k - i <= j - 1 && i >= 0; i--) {
                sum += f[i][j-1];
                sum %= M;
            }
            for(int i = k, ii = k - j;  i >= 1; i--, ii--) {
                f[i][j] = sum;
                sum -= f[i][j-1];
                if(ii >= 0) {
                    sum += f[ii][j-1];
                }
                sum += M;
                sum %= M;
            }
        }
        return f[k][n];
    }
};
