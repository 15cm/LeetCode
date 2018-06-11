class Solution {
    const int M = 1000000007;
public:
    int kInversePairs(int n, int k) {
        vector<int> f(k + 1);
        for(int j = 1; j <= n; j++) {
            f[0] = 1;
            long sum = 0;
            for(int i = k;  k - i <= j - 1 && i >= 0; i--) {
                sum += f[i];
                sum %= M;
            }
            for(int i = k, ii = k - j;  i >= 1; i--, ii--) {
                int tmp = f[i];
                f[i] = sum;
                sum -= tmp;
                if(ii >= 0) {
                    sum += f[ii];
                }
                sum = (sum + M) % M;
            }
        }
        return f[k];
    }
};
