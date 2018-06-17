#define LL long long
class Solution {
    const int M = 1000000007;
public:
    int findDerangement(int n) {
        if(n == 1) return 0;
        LL f0 = 1, f1 = 0, f2 = f0 + f1;
        for(int i = 3; i <= n; i++) {
            LL t1 = f1, t2 = f2;
            f2 = ((i - 1) * ((f1 + f2) % M) % M);
            f0 = t1;
            f1 = t2;
        }
        return f2;
    }
};
