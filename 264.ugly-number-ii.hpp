class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;
        vector<int> f(n);
        f[0] = 1;
        int factors[3] = {2,3,5};
        int ptrs[3] = {0,0,0};
        for(int i = 1; i < n; i++) {
            f[i] = INT_MAX;
            for(int j = 0; j < 3; j++)
                f[i] = min(f[i], f[ptrs[j]] * factors[j]);
            for(int j = 0; j < 3; j++)
                if(f[i] == f[ptrs[j]] * factors[j])
                    ptrs[j]++;
        }
        return f[n-1];
    }
};
