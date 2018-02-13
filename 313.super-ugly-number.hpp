class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        vector<int> ptr(m), f(n);
        f[0] = 1;
        for(int i = 1; i < n; i++) {
            f[i] = INT_MAX;
            for(int j = 0; j < m; j++) {
                f[i] = min(f[i], f[ptr[j]] * primes[j]);
            }
            for(int j = 0; j < m; j++) {
                if(f[i] == f[ptr[j]] * primes[j])
                    ptr[j]++;
            }
        }
        return f[n-1];
    }
};
