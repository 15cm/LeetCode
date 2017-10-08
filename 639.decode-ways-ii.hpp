#define MOD 1000000007
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<long> f(n+1);
        f[0] = 1;
        f[1] = s[0] == '0' ? 0 : s[0] == '*' ? 9 : 1;
        for(int i = 1; i < n; i++) {
            int k = i + 1;
            if(s[i] == '*') {
                f[k] = f[k - 1] * 9;
                switch(s[i-1]) {
                case '1':
                    f[k] += 9 * f[k - 2];
                    break;
                case '2':
                    f[k] += 6 * f[k - 2];
                    break;
                case '*':
                    f[k] += 15 * f[k - 2];
                    break;
                };
            } else {
                if(s[i] != '0') f[k] += f[k-1];
                if(s[i-1] == '1' || s[i-1] == '2' && s[i] >= '0' && s[i] <= '6') {
                    f[k] += f[k-2];
                } else if(s[i-1] == '*') {
                    f[k] += (s[i] >= '0' && s[i] <= '6' ? 2 : 1) * f[k-2];
                }
            }
            f[k] %= MOD;
        }
        return f[n];
    }
};
