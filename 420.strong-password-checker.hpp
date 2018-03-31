class Solution {
public:
    int strongPasswordChecker(string s) {
        int locase, upcase, digit;
        locase = upcase = digit = 1;
        int n = s.size();
        vector<int> cnts;
        int ans = 0;

        for(int i = 0, j = -1; i < n; i++) {
            char c = s[i];
            if(islower(c)) locase = 0;
            if(isupper(c)) upcase = 0;
            if(isdigit(c)) digit = 0;
            if(i+1 == n || s[i+1] != s[i]) {
                cnts.push_back(i-j);
                j = i;
            }
        }
        int missing = locase + upcase + digit;

        if(n < 6) {
            ans = missing + max(0, 6 - (n + missing));
        } else {
            int overLen = max(0, n - 20), leftOver = 0;
            int m = cnts.size();
            ans = overLen;

            // better than k == 3: delete until cnts[i] == 2
            for(int k = 1; k < 3; k++) {
                for(int i = 0; i < m && overLen > 0; i++) {
                    if(cnts[i] >= 3 && cnts[i] % 3 == k-1) {
                        cnts[i] -= min(overLen, k);
                        overLen -= k;
                    }
                }
            }

            for(int i = 0; i < m; i++) {
                if(cnts[i] >= 3 && overLen > 0) {
                    int need = cnts[i] - 2;
                    cnts[i] -= overLen; // min(need, overLen) in fact
                    overLen -= need;
                }
                if(cnts[i] >= 3) {
                    leftOver += cnts[i] / 3;
                }
            }

            ans += max(missing, leftOver);
        }
        return ans;
    }
};
