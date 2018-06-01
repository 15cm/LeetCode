#define LL long long
class Solution {
public:
    int checkRecord(int n) {
        LL M = 1000000007;
        vector<LL> f(n <= 5 ? 6 : n+1);
        f[0] = 1;
        f[1] = 2;
        f[2] = 4;
        for(int i = 3; i <= n; i++) {
            f[i] = (((f[i - 1] + f[i - 2]) % M) + f[i - 3]) % M;
        }
        LL sum = f[n];
        for(int i = 1; i <= n; i++)
            sum += (f[i - 1] * f[n - i]) % M;
        return sum % M;
    }
};
