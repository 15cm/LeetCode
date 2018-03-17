class Solution {
    int m = 1337;
public:
    int superPow(int a, vector<int>& b) {
        int res = 1;
        a %= m;
        for(int i = b.size() - 1; i >= 0; i--) {
            if(b[i] != 0)
                res = res * modpow(a, b[i]) % m;
            a = modpow(a, 10);
        }
        return res;
    }
    int modpow(int n, int p) {
        if(p == 0) return 1;
        if(p & 1)
            return modpow(n, p-1) * n % m;
        return modpow(n, p/2) * modpow(n, p/2) % m;
    }
};
