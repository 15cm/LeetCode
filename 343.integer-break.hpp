class Solution {
public:
    int integerBreak(int n) {
        vector<int> f(n+1);
        f[1] = 1;
        for(int i = 2; i <= n; i++) {
            for(int k = 1; k < i; k++) {
                f[i] = max(f[i], max(f[i-k], i-k) * max(f[k], k));
            }
        }
        return f[n];
    }
};
