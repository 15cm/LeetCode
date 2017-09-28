class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if(n == 0) return 0;
        int f[n+1] = {0};
        f[n] = 1;
        f[n-1] = s[n-1] == '0' ? 0 : 1;
        for(int i = n-2; i >= 0; i--) {
            if(s[i] == '0') continue;
            f[i] = stoi(s.substr(i, 2)) <= 26 ? f[i+1] + f[i+2] : f[i+1];
        }
        return f[0];
    }
};
